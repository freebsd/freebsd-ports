# New ports collection makefile for:    chntpw
# Date created:                         25 July 2007
# Whom:                    buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	chntpw
PORTVERSION=	100627
CATEGORIES=	security sysutils
MASTER_SITES=	http://pogostick.net/~pnh/ntpasswd/
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Utility to set the password and edit registry on Microsoft NT system

USE_ZIP=	yes
USE_GMAKE=	yes
USE_OPENSSL=	yes

ONLY_FOR_ARCHS=	i386

PLIST_FILES=	bin/chntpw
PORTDOCS=	README.txt WinReg.txt regedit.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e '10 s,/usr,$$\(OPENSSLBASE\),' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/chntpw ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
