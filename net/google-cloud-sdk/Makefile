PORTNAME=	google-cloud-sdk
DISTVERSION=	536.0.1
CATEGORIES=	net
MASTER_SITES=	https://dl.google.com/dl/cloudsdk/channels/rapid/downloads/
DISTNAME=	google-cloud-sdk-${PORTVERSION}-linux-x86_64

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Google Cloud SDK for Google Cloud Platform
WWW=		https://developers.google.com/cloud/sdk/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		python

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/google-cloud-sdk

PLIST_FILES=	bin/bq \
		bin/docker-credential-gcloud \
		bin/gcloud \
		bin/git-credential-gcloud.sh \
		bin/gsutil

post-extract:
	@${RM} -r \
		${WRKSRC}/bin/anthoscli \
		${WRKSRC}/bin/kuberun \
		${WRKSRC}/bin/gcloud-crc32c \
		${WRKSRC}/install.bat \
		${WRKSRC}/platform/bundledpythonunix \
		${WRKSRC}/platform/gsutil/third_party/crcmod/docs/source/make.bat \
		${WRKSRC}/platform/gsutil/third_party/rsa/doc/make.bat \
		${WRKSRC}/rpm \
		${WRKSRC}/deb \
		${WRKSRC}/lib/third_party/grpc/_cython/cygrpc.so

do-install:
	${RM} -r ${WRKSRC}/help ${WRKSRC}/.install/.download
	( cd ${WRKSRC} ; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/google-cloud-sdk )
.for x in bq docker-credential-gcloud gcloud git-credential-gcloud.sh gsutil
	${CHMOD} +x ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x}
	${RLN} ${STAGEDIR}${PREFIX}/google-cloud-sdk/bin/${x} \
		${STAGEDIR}${PREFIX}/bin/${x}
.endfor

post-install:
	@(cd ${STAGEDIR}${PREFIX} && \
		${FIND} -s google-cloud-sdk -type f -o -type l >> ${TMPPLIST})

.include <bsd.port.mk>
