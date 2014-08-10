# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-sdk
PORTVERSION=	0.0.0.0.20140809
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/release/
DISTNAME=	google-cloud-sdk-coretools-linux-x86_64

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Google Cloud SDK for Google Cloud Platform

USES=		python
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/google-cloud-sdk

do-install:
	${FIND} ${WRKSRC}/help -type f -name '*.1' -exec ${GZIP_CMD} {} +
	( cd ${WRKSRC}/help ; ${COPYTREE_SHARE} man ${STAGEDIR}${PREFIX} )
	${RM} -r ${WRKSRC}/help/man
	( cd ${WRKSRC} ; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/google-cloud-sdk )
.for x in bq gcloud gcutil git-credential-gcloud.sh gsutil
	${CHMOD} +x ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x}
	${LN} -s ${PREFIX}/google-cloud-sdk/bin/${x} ${STAGEDIR}${PREFIX}/bin/${x}
.endfor

.include <bsd.port.mk>
