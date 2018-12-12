# Created by: Mageirias Anastasios <anastmag@gmail.com>
# $FreeBSD$

PORTNAME=	clamfs
PORTVERSION=	1.0.1
PORTREVISION=	11
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	anastasios@mageirias.com
COMMENT=	User-space fs with on-access antivirus scanning

LICENSE=	GPLv2

BROKEN_armv6=		fails to compile: ./config.hxx:52:17: expected namespace name
BROKEN_armv7=		fails to compile: ./config.hxx:52:17: expected namespace name

LIB_DEPENDS=	libccgnu2.so:devel/commoncpp \
		libPocoNet.so:devel/poco-ssl \
		librlog.so:devel/rlog
BUILD_DEPENDS=	boost-libs>=1.33:devel/boost-libs
RUN_DEPENDS=	clamd:security/clamav

GNU_CONFIGURE=	yes

USES=		compiler:c++11-lib fuse

PLIST_FILES=	bin/clamfs \
		man/man1/clamfs.1.gz

OPTIONS_DEFINE=	DOCS
DOCS_PORTDOCS=	*

post-patch-DOCS-on:
	@${REINPLACE_CMD} -e '/socket=/s/ctl/sock/' \
		${WRKSRC}/doc/clamfs.xml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/clamfs.xml ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
