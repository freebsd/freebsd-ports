# New ports collection makefile for:	pine
# http://www.washington.edu/pine/
# Version required:     4.05
# Date created:		09 July 1998
# Whom:			Adrian Penisoara <ady@freebsd.ady.ro>
#
# $Id: Makefile,v 1.27 1998/10/05 04:23:13 steve Exp $
#

DISTNAME=       pine4.05
PKGNAME=        pine-4.05
CATEGORIES=     mail news
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/

MAINTAINER=	pine@freebsd.ady.ro

Y2K=		http://www.washington.edu/pine/QandA/sysadmins.html#Millenium

NO_LATEST_LINK= yes

MAN1= 		pine.1 pico.1 pilot.1

post-patch:
	for i in ${WRKSRC}/doc/pine.1 \
		${WRKSRC}/pine/init.c \
		${WRKSRC}/pine/pine.hlp \
		${WRKSRC}/pine/mailcap.c \
		${WRKSRC}/pine/osdep/os-bsf.h ; do \
		${MV} $$i $$i.sed ; \
		${SED} -e "s:@@PREFIX@@:${PREFIX}:g" \
			$$i.sed >$$i ; \
		${RM} $$i.sed ; \
	done
	for i in ${WRKSRC}/doc/tech-notes.txt \
		${WRKSRC}/doc/tech-notes/*.html ; do \
		${MV} $$i $$i.sed ; \
		${SED} -e "s:/usr/local/lib/:${PREFIX}/etc/:g" \
			$$i.sed >$$i ; \
		${RM} $$i.sed ; \
	done

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ./build bsf)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pico ${PREFIX}/bin/pico
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pilot ${PREFIX}/bin/pilot
	${INSTALL_PROGRAM} ${WRKSRC}/bin/pine ${PREFIX}/bin/pine
	${INSTALL_SCRIPT} ${FILESDIR}/pgpencrypt ${PREFIX}/bin/pgpencrypt
	${INSTALL_SCRIPT} ${FILESDIR}/pgpdecode ${PREFIX}/bin/pgpdecode
	${INSTALL_SCRIPT} ${FILESDIR}/pgpsign ${PREFIX}/bin/pgpsign
	${INSTALL_DATA} ${FILESDIR}/dot.pinerc.pgp.sample \
			${PREFIX}/etc/dot.pinerc.pgp.sample
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1/pico.1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1/pilot.1
	${INSTALL_MAN} ${WRKSRC}/doc/pine.1 ${PREFIX}/man/man1/pine.1
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} \
			${PREFIX}/share/doc/pine \
			${PREFIX}/share/doc/pine/tech-notes
	${INSTALL_DATA} ${WRKSRC}/doc/brochure.txt ${PREFIX}/share/doc/pine
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes.txt ${PREFIX}/share/doc/pine
	${INSTALL_DATA} ${WRKSRC}/doc/tech-notes/*.html \
			${PREFIX}/share/doc/pine/tech-notes/
.endif

post-install:
	${PREFIX}/bin/pine -P ${PREFIX}/etc/pine.conf -conf >${WRKSRC}/pine.conf
	${INSTALL_DATA} ${WRKSRC}/pine.conf ${PREFIX}/etc/pine.conf
	@${ECHO} "	- - - - - - - - - - - - - - - - - - - - - - - - -"
	@${ECHO} "	If Pine exits with \"Received abort signal\" try"
	@${ECHO} "	disabling the \"quell-folder-internal-msg\" feature"
	@${ECHO} "	- - - - - - - - - - - - - - - - - - - - - - - - -"

.include <bsd.port.mk>
