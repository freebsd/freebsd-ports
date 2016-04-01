# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-sdk
PORTVERSION=	94.0.0
PORTREVISION=	0
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/release/packages/
DISTNAME=	google-cloud-sdk-coretools-linux-static-20160122113408

# new releases listed in https://dl.google.com/dl/cloudsdk/release/sha1.txt

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Google Cloud SDK for Google Cloud Platform

USES=		python
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/google-cloud-sdk

RUN_DEPENDS=	python:lang/python

post-extract:
	@${RM} ${WRKSRC}/install.bat
	@${RM} ${WRKSRC}/platform/gsutil/third_party/crcmod/docs/source/make.bat
	@${RM} ${WRKSRC}/platform/gsutil/third_party/rsa/doc/make.bat

do-install:
	${FIND} ${WRKSRC}/help -type f -name '*.1' -exec ${GZIP_CMD} {} +
	( cd ${WRKSRC}/help ; ${COPYTREE_SHARE} man ${STAGEDIR}${PREFIX} )
	${RM} -r ${WRKSRC}/help ${WRKSRC}/.install/.download
	( cd ${WRKSRC} ; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/google-cloud-sdk )
.for x in bq gcloud git-credential-gcloud.sh gsutil
	${CHMOD} +x ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x}
	${LN} -s ${PREFIX}/google-cloud-sdk/bin/${x} ${STAGEDIR}${PREFIX}/bin/${x}
.endfor

.include <bsd.port.mk>
