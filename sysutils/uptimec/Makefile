# New ports collection makefile for:	uptimec
# Date created:		5 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	uptimec
PORTVERSION=	0.2p2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mrEriksson.net/downloads/ \
		ftp://ftp.mrEriksson.net/pub/uptimec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client for Uptime Project

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_RC_SUBR=	yes

PLIST_FILES=	sbin/uptimec etc/uptimecrc.sample etc/rc.d/uptimec.sh
PORTDOCS=	README COPYING ChangeLog INSTALL protocol.txt

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/uptimec ${PREFIX}/sbin
		${INSTALL_DATA} ${MASTERDIR}/files/uptimecrc.sample ${PREFIX}/etc
		${INSTALL_SCRIPT} ${WRKSRC}/uptimec.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
	${FILESDIR}/uptimec.sh > ${WRKSRC}/uptimec.sh

post-install:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${PKGMESSAGE}

.include <bsd.port.mk>
