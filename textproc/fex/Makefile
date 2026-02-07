PORTNAME=	fex
PORTVERSION=	2.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Powerful field extraction tool
WWW=		https://semicomplete.com/projects/fex/

LICENSE=	APACHE20

USES=		perl5
USE_PERL5=	build # pod2man
USE_GITHUB=	yes
GH_ACCOUNT=	jordansissel

MAKE_ENV+=	INSTALLMAN=${PREFIX}/share/man

PLIST_FILES=	bin/fex share/man/man1/fex.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|CC=gcc|CC=${CC}|g' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
