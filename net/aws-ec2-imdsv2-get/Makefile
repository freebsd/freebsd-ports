PORTNAME=	aws-ec2-imdsv2-get
DISTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	net

MAINTAINER=	cperciva@FreeBSD.org
COMMENT=	Reads data from EC2 IMDS with v2 protocol
WWW=		https://github.com/aws/aws-ec2-imdsv2-get

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	aws

PORTDOCS=	NOTICE README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
