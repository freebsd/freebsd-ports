# ex:ts=8
# New ports collection makefile for:    mutt w/pgp hooks
# Version required:     0.xy
# Date created:         Thur July 25, 1996
# Whom:                 David O'Brien (obrien@NUXI.com)
#
# $Id: Makefile,v 1.32 1997/05/17 05:34:22 obrien Exp $

BASEDIST=	mutt-0.74
DISTNAME=	${BASEDIST}
PKGNAME=	mutt-pgp-0.74
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.cs.hmc.edu/pub/me/mutt/
MASTER_SITE_OVERRIDE=

PATCH_SITES=    http://www.frmug.org/mutt/mutt/0.73/  \
		http://www.math.fu-berlin.de/~leitner/mutt/0.73/  \
		http://www.efrei.fr/~parmelan/mutt/0.73/  \
		ftp://www.frmug.org/pub/mutt/mutt/0.73/
PATCHFILES=

MAINTAINER=     obrien@FreeBSD.org

# Need to define USA_RESIDENT to YES or NO
RESTRICTED=	"USA ITAR export restrictions (has PGP hooks)"

DIST_SUBDIR=	mutt
#PATCH_DIST_STRIP=	-p2
PATCH_DIST_STRIP=	-p1
#PATCH_DIST_STRIP=	
GNU_CONFIGURE=	yes
MAN1=		mutt.1

.if !defined(USA_RESIDENT) || (${USA_RESIDENT} != YES && ${USA_RESIDENT} != yes && ${USA_RESIDENT} != NO && ${USA_RESIDENT} != no)
pre-fetch:
	@echo
	@echo You must set variable USA_RESIDENT to YES, if you are USA resident,
	@echo or to NO if you aren\'t a USA resident in order to build this package
	@false

.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES || ${USA_RESIDENT} == yes
#	can't grab patches from Nuxi unless you are in USA/Canada
PATCH_SITES:=	ftp://ftp.nuxi.com/pub/mutt/${BASEDIST:S/^mutt-//}/  \
		${PATCH_SITES}
pre-fetch:	# don't use "do-fetch" otherwise we won't get the patches
	@${MKDIR} ${DISTDIR}/${DIST_SUBDIR}
	@(cd ${DISTDIR}/${DIST_SUBDIR} ; \
	if [ ! -f ${DISTFILES} -a ! -f `${BASENAME} ${DISTFILES}` ]; then \
		${FETCH_CMD} -o /tmp/README.US-only ${MASTER_SITES}README.US-only ; \
		sed -e 's:US-only/.*:&:w /tmp/muttusa.dir' /tmp/README.US-only >/dev/null ; \
		USADISTRIB=`sed -e 's:^.*US-only/::' /tmp/muttusa.dir` ; \
		${FETCH_CMD} -m ${FETCH_BEFORE_ARGS} ${MASTER_SITES}US-only/$$USADISTRIB/${DISTNAME}${EXTRACT_SUFX} ${FETCH_AFTER_ARGS} ; \
		/bin/rm -f /tmp/README.US-only /tmp/muttusa.dir ; \
	fi)
FILESDIR=       ${.CURDIR}/files.usa

.else	#non-USA resident
DISTNAME=	${BASEDIST}e
FILESDIR=	${.CURDIR}/files.non_usa
MASTER_SITES:=	ftp://ftp.ibp.fr/pub/unix/mail/mutt/mutt/  \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/  \
		ftp://ftp.teuto.de/pub/user/lmb/  \
		ftp://ftp.funet.fi/pub/unix/mail/mutt/ \
		${MASTER_SITES}
#       01.pgp.1 needs to be applied before all others!
PATCHFILES:=    01.pgp.1 ${PATCHFILES}
WRKSRC=		${WRKDIR}/${BASEDIST}

.endif		# USA resident = yes
.endif		# USA resident set


post-install:
	@####   don't strip until out of beta peroid
	@#strip ${PREFIX}/bin/mutt
.if !defined(NOPORTDOCS)
	@${ECHO} "===>   Installing Mutt documentation"
	@${MKDIR} ${PREFIX}/share/doc/mutt && chmod a+rx ${PREFIX}/share/doc/mutt
	@${INSTALL_MAN} ${WRKSRC}/doc/*.latin1 ${WRKSRC}/doc/*.html  \
		${PREFIX}/share/doc/mutt
	@(cd ${WRKSRC} ; ${INSTALL_DATA} sample.muttrc Mush.rc Pine.rc  \
		${PREFIX}/share/doc/mutt)
.endif

.include <bsd.port.mk>
