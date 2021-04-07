PORTNAME=	ocsinventory-server
PORTVERSION=	2.8
CATEGORIES=	net-mgmt

MAINTAINER=	dgeo@centrale-marseille.fr
COMMENT=	Open Computer and Software Inventory Next Generation

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-XML-Simple>=2.12:textproc/p5-XML-Simple \
		p5-DBI>=1.40:databases/p5-DBI \
		p5-DBD-mysql>=2.9004:databases/p5-DBD-mysql \
		p5-Apache-DBI>=0.93:www/p5-Apache-DBI \
		p5-Net-IP>=1.21:net-mgmt/p5-Net-IP \
		p5-SOAP-Lite>=0.66:net/p5-SOAP-Lite \
		p5-XML-Entities>=0.02:textproc/p5-XML-Entities \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Apache2-SOAP>=0:net/p5-Apache2-SOAP \
		p5-Mojolicious>=0:www/p5-Mojolicious \
		p5-Switch>=0:lang/p5-Switch \
		p5-Plack>=0:www/p5-Plack

USES=		apache:run,2.2+ mysql perl5
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
USE_GITHUB=	YES
GH_ACCOUNT=	OCSInventory-NG
GH_PROJECT=	OCSInventory-Server

OPTIONS_DEFINE=	DOCS OCSREPORTS
OPTIONS_DEFAULT=	OCSREPORTS
OCSREPORTS_DESC=	Install ocsreports admin console
OCSREPORTS_RUN_DEPENDS=	ocsinventory-ocsreports>=0:net-mgmt/ocsinventory-ocsreports

ETCDIR=	${PREFIX}/etc/ocsinventory-server

post-patch:
	${REINPLACE_CMD} -e 's|REST_API_LOADER_PATH|${SHAREDIR}/Api/Ocsinventory/Restapi/Loader.pm|g' ${WRKSRC}/etc/ocsinventory/ocsinventory-restapi.conf
	${REINPLACE_CMD} -e 's|REST_API_PATH|${SHAREDIR}|g;' ${WRKSRC}/etc/ocsinventory/ocsinventory-restapi.conf
	${REINPLACE_CMD} -e 's|LOCALBASE|${LOCALBASE}|g;' ${WRKSRC}/etc/ocsinventory/ocsinventory-server.conf

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "Apache Api binutils dtd" ${STAGEDIR}${DATADIR}/)
	${INSTALL_SCRIPT} ${WRKSRC}/setup.sh ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${ETCDIR}
.for F in restapi server
	${INSTALL_DATA} ${WRKSRC}/etc/ocsinventory/ocsinventory-${F}.conf ${STAGEDIR}${ETCDIR}/ocsinventory-${F}.conf.sample
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
