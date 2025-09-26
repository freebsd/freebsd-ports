PORTNAME=	claude-code
DISTVERSION=	1.0.126
CATEGORIES=	misc # machine-learning

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Agentic coding tool from Anthropic that lives in your terminal
WWW=		https://github.com/anthropics/claude-code

FETCH_DEPENDS=	npm:www/npm

USES=		nodejs:run

NO_BUILD=	yes
NO_ARCH=	yes

do-fetch:
	@if ! [ -f ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} ]; then \
		npm install --prefix ${WRKSRC} -g @anthropic-ai/claude-code@${DISTVERSION} && \
		${FIND} ${WRKDIR} -and -exec ${TOUCH} -h -d 1970-01-01T00:00:00Z {} \; && \
		cd ${WRKDIR} && ${FIND} ${PORTNAME}-${DISTVERSION} -print0 | LC_ALL=C ${SORT} -z | \
	        	${TAR} czf ${DISTDIR}/${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} --format=bsdtar --gid 0 --uid 0 --options gzip:!timestamp --no-recursion --null -T -; \
	fi

do-install:
	# install files
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}
	# update
	${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/env node|#!${PREFIX}/bin/node|" \
		${STAGEDIR}${PREFIX}/lib/node_modules/@anthropic-ai/claude-code/cli.js
	# set exec bit
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/node_modules/@anthropic-ai/claude-code/cli.js

.include <bsd.port.mk>
