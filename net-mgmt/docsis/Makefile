# Created by: James Flemer <jflemer@acm.jhu.edu>
# $FreeBSD$

PORTNAME=	docsis
PORTVERSION=	0.9.6
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Binary configuration file encoder/decoder

LICENSE=	GPLv2+

BUILD_DEPENDS=	gm4:devel/m4
LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		bison

PLIST_SUB=	MIBS=share/snmp/mibs

BROKEN_amd64=	Produces corrupt files on amd64

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e \
		'/^htmldocdir/s|share/docsis|share/doc/docsis|' \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^examplesdir/s|docsis/examples|examples/docsis|' \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.mk>
