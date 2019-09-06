# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	mdf2iso
PORTVERSION=	0.3.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/m/${PORTNAME}
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig.tar.gz ${PORTNAME}_${PORTVERSION}-${DEBIANVERSION}.debian.tar.xz  

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Alcohol 120% to ISO converter

LICENSE=	GPLv2+

DEBIANVERSION=	2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

INSTALL_TARGET=	install-strip

post-install:
		${INSTALL_MAN} ${WRKDIR}/debian/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
