# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-sdk
PORTVERSION=	0.9.41
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/release/packages/
DISTNAME=	google-cloud-sdk-coretools-linux-static-20141219112406

# new releases listed in https://dl.google.com/dl/cloudsdk/release/sha1.txt

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Google Cloud SDK for Google Cloud Platform

USES=		python
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/google-cloud-sdk

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

post-extract:
	-@${RM} ${WRKSRC}/platform/gcutil/lib/iso8601/iso8601/.*

do-install:
	${FIND} ${WRKSRC}/help -type f -name '*.1' -exec ${GZIP_CMD} {} +
	( cd ${WRKSRC}/help ; ${COPYTREE_SHARE} man ${STAGEDIR}${PREFIX} )
	${RM} -r ${WRKSRC}/help/man ${WRKSRC}/.install/.download
	( cd ${WRKSRC} ; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/google-cloud-sdk )
.for x in bq gcloud gcutil git-credential-gcloud.sh gsutil
	${CHMOD} +x ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x}
	${LN} -s ${PREFIX}/google-cloud-sdk/bin/${x} ${STAGEDIR}${PREFIX}/bin/${x}
.endfor

.include <bsd.port.mk>
