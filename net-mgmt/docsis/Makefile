# Created by: James Flemer <jflemer@acm.jhu.edu>
# $FreeBSD$

PORTNAME=	docsis
PORTVERSION=	0.9.8
DISTVERSIONPREFIX=	upstream/
CATEGORIES=	net-mgmt

MAINTAINER=	plcmaechler@gmail.com
COMMENT=	Binary configuration file encoder/decoder

LICENSE=	GPLv2+

BUILD_DEPENDS=	flex:textproc/flex
LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp \
		libpkg.so:ports-mgmt/pkg

USES=		autoreconf bison libtool ssl
USE_GITHUB=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
BINARY_WRAPPERS=	gm4

PLIST_SUB=	MIBS=share/snmp/mibs

OPTIONS_DEFINE=	DOCS EXAMPLES

GH_ACCOUNT=	rlaager

post-patch:
	@${REINPLACE_CMD} -e \
		'/^htmldocdir/s|share/docsis|share/doc/docsis|' \
		${WRKSRC}/doc/Makefile.am
	@${REINPLACE_CMD} -e \
		'/^examplesdir/s|docsis/examples|examples/docsis|' \
		${WRKSRC}/examples/Makefile.am

.include <bsd.port.mk>
