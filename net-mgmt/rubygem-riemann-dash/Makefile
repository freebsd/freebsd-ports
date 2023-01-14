PORTNAME=	riemann-dash
DISTVERSION=	0.2.14
CATEGORIES=	net-mgmt rubygems
MASTER_SITES=	RG

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Configurable websocket/javascript based dashboard for net-mgmt/riemann
WWW=		https://github.com/riemann/riemann-dash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-multi_json>=0:devel/rubygem-multi_json \
		rubygem-sass>=0:textproc/rubygem-sass \
		rubygem-erubis>=0:www/rubygem-erubis \
		rubygem-sinatra>=0:www/rubygem-sinatra

USES=		gem

NO_ARCH=	yes

post-install:
	# move the public HTML files into DATADIR for webservers
	# even when the package version & path changes
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MV} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/riemann/dash/public \
		${STAGEDIR}${DATADIR}/www
# the eruby template is valid HTML so drop it into public dir
	# and it can all be served directly via your webserver
	${CP}	${WRKSRC}/lib/riemann/dash/views/index.erubis \
		${STAGEDIR}${DATADIR}/www/index.html

.include <bsd.port.mk>
