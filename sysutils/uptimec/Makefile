# New ports collection makefile for:	uptimec
# Date created:		5 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	uptimec
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.mrEriksson.net/downloads/

MAINTAINER=	hsn@netmag.cz
COMMENT=	Client for Uptime Project

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	257
USE_REINPLACE=	yes

PLIST_FILES=	sbin/uptimec etc/uptimecrc.sample etc/rc.d/uptimec.sh
PORTDOCS=	README COPYING ChangeLog INSTALL protocol.txt

post-patch:
	@${REINPLACE_CMD} -e 's|CC =|CC ?=|g' ${WRKSRC}/Makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/uptimec ${PREFIX}/sbin
		${INSTALL_DATA} ${MASTERDIR}/files/uptimecrc.sample ${PREFIX}/etc
		${INSTALL_SCRIPT} ${MASTERDIR}/files/uptimec.sh ${PREFIX}/etc/rc.d
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${SED} -e 's,%%LOCALBASE%%,${LOCALBASE},' ${PKGMESSAGE}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
