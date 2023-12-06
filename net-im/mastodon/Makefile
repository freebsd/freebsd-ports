PORTNAME=	mastodon
DISTVERSIONPREFIX=	v
DISTVERSION=	4.2.3
CATEGORIES=	net-im www

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GNU Social-compatible microblogging server
WWW=		https://github.com/tootsuite/mastodon

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
		sudo>0:security/sudo \
		wget>0:ftp/wget \
		yarn>:www/yarn

USES=		magick:7,run pgsql
USE_GITHUB=	yes
USE_RC_SUBR=	mastodon_sidekiq mastodon_streaming mastodon_web

NO_ARCH=	yes
NO_BUILD=	yes

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

RM_MASTODONFILES=	.dockerignore dist/mastodon-web.service \
			dist/mastodon-sidekiq.service \
			dist/mastodon-streaming.service \
			docker-compose.yml \
			Dockerfile \
			Vagrantfile
RM_MASTODONDIRS=	.circleci .devcontainer .github

post-extract:
.for _F in ${RM_MASTODONFILES}
	@${RM} ${WRKSRC}/${_F}
.endfor
.for _D in ${RM_MASTODONDIRS}
	@${RM} -r ${WRKSRC}/${_D}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|'\
		${WRKSRC}/dist/nginx.conf

do-install:
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name '*.bak' -delete
	${FIND} ${WRKSRC} -name '*.gitkeep' -delete
	${FIND} ${WRKSRC} -name '*.gitignore' -delete
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
