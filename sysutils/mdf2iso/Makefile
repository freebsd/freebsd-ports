PORTNAME=	mdf2iso
PORTVERSION=	0.3.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	DEBIAN
DISTFILES=	${PORTNAME}_${PORTVERSION}.orig.tar.gz ${PORTNAME}_${PORTVERSION}-${DEBIANVERSION}.debian.tar.xz

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Alcohol 120% to ISO converter
WWW=		https://BSDforge.com/projects/sysutils/mdf2iso/

LICENSE=	GPLv2+

DEBIANVERSION=	2
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

INSTALL_TARGET=	install-strip

post-install:
		${INSTALL_MAN} ${WRKDIR}/debian/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
