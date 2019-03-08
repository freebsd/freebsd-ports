# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-cloud-sdk
PORTVERSION=	237.0.0
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/channels/rapid/downloads/
DISTNAME=	google-cloud-sdk-${PORTVERSION}-linux-x86_64

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Google Cloud SDK for Google Cloud Platform

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python:2.7
WRKSRC=		${WRKDIR}/google-cloud-sdk
NO_ARCH=	yes

PLIST_FILES=	bin/bq bin/gcloud bin/git-credential-gcloud.sh bin/gsutil

post-extract:
	@${RM} -r \
		${WRKSRC}/install.bat \
		${WRKSRC}/platform/gsutil/third_party/crcmod/docs/source/make.bat \
		${WRKSRC}/platform/gsutil/third_party/rsa/doc/make.bat \
		${WRKSRC}/rpm \
		${WRKSRC}/deb \
		${WRKSRC}/lib/third_party/grpc/_cython/cygrpc.so

do-build:
	@cd ${WRKSRC} ; \
		${PYTHON_CMD} -m compileall -q -x python3 .

do-install:
	${RM} -r ${WRKSRC}/help ${WRKSRC}/.install/.download
	( cd ${WRKSRC} ; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/google-cloud-sdk )
.for x in bq gcloud git-credential-gcloud.sh gsutil
	${CHMOD} +x ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x}
	${RLN} ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x} \
		${STAGEDIR}${PREFIX}/bin/${x}
.endfor

post-install:
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s google-cloud-sdk -type f -o -type l >> ${TMPPLIST})

.include <bsd.port.mk>
