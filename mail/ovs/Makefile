PORTNAME=	ovs
PORTVERSION=	1.06
CATEGORIES=	mail

MAINTAINER=	ports@FreeBSD.org
COMMENT=	RRDtool frontend for mail statistics
WWW=		https://github.com/xbeaudouin/openvisp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-File-Tail>=0:devel/p5-File-Tail \
		rrdtool>=0:databases/rrdtool

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	xbeaudouin
GH_PROJECT=	openvisp
GH_TAGNAME=	1e17895bbcb70ee66370676546d17e540e629b08
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	ovs.cgi ovs.pl

CGIDIR?=	${PREFIX}/www/cgi-bin
DATADIR?=	/var/db/ovs
NO_ARCH=	yes
NO_BUILD=	yes

WWWROOT?=	${PREFIX}/www/data
OVS_USER?=	${WWWOWN}
OVS_GROUP?=	${WWWGRP}

SUB_LIST+=	OVS_GROUP=${OVS_GROUP} \
		OVS_USER=${OVS_USER}

WRKSRC_SUBDIR=	stats/trunk/

PLIST_SUB=	CGIDIR=${CGIDIR:S,${PREFIX}/,,} \
		OVS_GROUP=${OVS_GROUP} \
		OVS_USER=${OVS_USER} \
		WWWROOT=${WWWROOT:S,${PREFIX}/,,}
PORTDOCS=	CHANGES CHANGES.old COPYING README README.old

OPTIONS_DEFINE=	DOCS

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may set following options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DATADIR=/var/db/ovs		Where do you put RRD databases?"
	@${ECHO_MSG} "CGIDIR=${PREFIX}/www/cgi-bin      Where do you put cgi?"
	@${ECHO_MSG} "WWWROOT=${PREFIX}/www/data        Where do you put httpd's document root?"
	@${ECHO_MSG} "OVS_USER=www			User to run mailgraph (Default: ${WWWOWN})"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR}," ${WRKSRC}/ovs.cgi

do-install:
	@${MKDIR} ${STAGEDIR}${CGIDIR}
	@${MKDIR} ${STAGEDIR}${WWWROOT}/ovs
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ovs.pl ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ovs.cgi ${STAGEDIR}${CGIDIR}
	${INSTALL_DATA} ${WRKSRC}/ovs.css ${STAGEDIR}${WWWROOT}/ovs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for f in ${PORTDOCS}; do \
	  ${INSTALL_DATA} ${WRKSRC}/$$f ${STAGEDIR}${DOCSDIR}; \
	done

.include <bsd.port.mk>
