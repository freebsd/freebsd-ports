PORTNAME=	mastodon
DISTVERSIONPREFIX=	v
DISTVERSION=	4.6.4
CATEGORIES=	net-im www

MAINTAINER=	saken@codered.rmta.org
COMMENT=	GNU Social-compatible microblogging server
WWW=		https://github.com/mastodon/mastodon/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libidn.so:dns/libidn
RUN_DEPENDS=	autoconf>=2.71:devel/autoconf \
		curl>0:ftp/curl \
		ffmpeg>0:multimedia/ffmpeg \
		git>=0:devel/git \
		gmake>0:devel/gmake \
		gnupg>0:security/gnupg \
		redis>0:databases/redis \
		rubygem-bundler>=0:sysutils/rubygem-bundler \
		wget>0:ftp/wget \
		yarn>:www/yarn

USES=		magick:7,run pgsql sudo
USE_GITHUB=	yes
USE_RC_SUBR=	mastodon_sidekiq mastodon_streaming mastodon_web

EXTRACT_AFTER_ARGS=	${.circleci .devcontainer .git* .dockerignore \
			dist/*.service docker-compose.yml \
			Dockerfile Vagrantfile:L:S|^|--exclude |} \
			--no-same-owner --no-same-permissions

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'\
		${WRKSRC}/dist/nginx.conf

do-install:
	${FIND} ${WRKSRC}  -name '*.orig' -delete \
			-o -name '*.bak'  -delete
	${MV} ${WRKSRC}/dist/nginx.conf ${WRKSRC}/dist/nginx.conf.sample
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/${PORTNAME})

post-install:
	@${ECHO_CMD} "@owner mastodon" >> ${TMPPLIST}
	@${ECHO_CMD} "@group mastodon" >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##' | \
		${SED} -E -e '/sample$$/ s#^#@sample #' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${WWWDIR} -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/#@dir #' >> ${TMPPLIST}

.include <bsd.port.mk>
