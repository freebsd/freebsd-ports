# New ports collection makefile for:	mmv
# Version required:	1.01b
# Date created:		2 Feb 1995
# Whom:			Michael Elbel (me)
#
# $Id: Makefile,v 1.12 1996/11/11 05:49:49 obrien Exp $
#

DISTNAME=	mmv
PKGNAME=	mmv-1.01b
CATEGORIES=	misc
MASTER_SITES=	ftp://gatekeeper.dec.com/pub/usenet/comp.sources.unix/
DISTFILES=	part01.Z part02.Z mmv.pch.Z

MAINTAINER=	me@FreeBSD.org

RESTRICTED=	"Restrictive copyright."
DIST_SUBDIR=	${DISTNAME}
SITE_DISTFILES= volume21/mmv/part01.Z volume21/mmv/part02.Z volume22/mmv.pch.Z
NO_WRKSUBDIR=	yes

# targets shamelessly hacked from the bsd.ports.mk file

do-fetch:
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@(cd ${DISTDIR}/${DIST_SUBDIR}; \
	 for file in ${SITE_DISTFILES}; do \
		if [ ! -f `basename $$file` ]; then \
			echo ">> `basename $$file` doesn't seem to exist on this system."; \
			echo ">> Attempting to fetch it from a master site."; \
			for site in ${MASTER_SITES}; do \
				pwd;\
				if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${file} ${FETCH_AFTER_ARGS}; then \
					break; \
				fi \
			done; \
			if [ ! -f `basename $$file` ]; then \
				echo ">> Couldn't fetch it - please try to retreive this";\
				echo ">> port manually into ${DISTDIR}/${DIST_SUBDIR} and try again."; \
				exit 1; \
			fi; \
	    fi \
	 done)

pre-extract:
	chmod +x scripts/unshar scripts/makeitapatch

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}/tmp
	@(cd ${DISTDIR}/${DIST_SUBDIR} ; for file in ${DISTFILES}; do \
		${CP} $$file ${WRKDIR}/tmp; \
	 done ; \
	 cd ${WRKDIR}/tmp; \
	 uncompress *; \
	 cd .. ; \
	 for file in tmp/part0* ; do \
	     ${SCRIPTDIR}/unshar $$file; \
	 done ; \
	 ${SCRIPTDIR}/makeitapatch tmp/mmv.pch ; \
	 mv tmp/mmv.pch ${PATCHDIR}/patch-0a ; \
	 ${CAT} mmv.c.? >mmv.c ; rm mmv.c.? )


do-install:
	(cd ${PREFIX}/bin ; rm -f mmv mad mcp mln ; \
	 cd ${WRKSRC}; \
	 ${INSTALL_PROGRAM} mmv ${PREFIX}/bin ; \
	 ln ${PREFIX}/bin/mmv ${PREFIX}/bin/mad ; \
	 ln ${PREFIX}/bin/mmv ${PREFIX}/bin/mcp ; \
	 ln ${PREFIX}/bin/mmv ${PREFIX}/bin/mln ; \
	 if [ ! -f mmv.1.gz ] ; then gzip mmv.1 ; fi ; \
	 if [ ! -d ${PREFIX}/man/man1 ]; then ${MKDIR} ${PREFIX}/man/man1; fi; \
	 ${INSTALL_MAN} mmv.1.gz ${PREFIX}/man/man1 ; )

pre-clean:
	@rm -f ${PATCHDIR}/patch-0a	# created by do-extract above

.include <bsd.port.mk>
