# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=		crits
PORTVERSION=		3.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=		security
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		dvl@FreeBSD.org
COMMENT=		Collaborative Research Into Threats

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

BROKEN=		Depends on conflicting versions of django

USE_GITHUB=		yes
GH_PROJECT=		crits

USES=			python
USE_PYTHON=		autoplist

USE_APACHE_RUN=	22+

LIB_DEPENDS+=	libpcre.so:${PORTSDIR}/devel/pcre  \
		libcurl.so:${PORTSDIR}/ftp/curl    \
		libpcap.so:${PORTSDIR}/net/libpcap

RUN_DEPENDS+=	7z:${PORTSDIR}/archivers/p7zip     \
		unrar:${PORTSDIR}/archivers/unrar  \
		upx:${PORTSDIR}/archivers/upx	   \
		zip:${PORTSDIR}/archivers/zip	   \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson  \
		${PYTHON_PKGNAMEPREFIX}curl>0:${PORTSDIR}/ftp/py-curl                 \
		${PYTHON_PKGNAMEPREFIX}pydot>=0:${PORTSDIR}/graphics/py-pydot         \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml               \
		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}numpy>0:${PORTSDIR}/math/py-numpy                   \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:${PORTSDIR}/math/py-matplotlib         \
		${PYTHON_PKGNAMEPREFIX}lxml>0:${PORTSDIR}/devel/py-lxml                    \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.2:${PORTSDIR}/devel/py-dateutil         \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:${PORTSDIR}/security/py-m2crypto         \
		mongodb>2.6.4:${PORTSDIR}/databases/mongodb                                \
		${PYTHON_PKGNAMEPREFIX}pymongo>=2.7.1:${PORTSDIR}/databases/pymongo        \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.4.1:${PORTSDIR}/devel/py-defusedxml   \
		${PYTHON_PKGNAMEPREFIX}django16>=1.6.5:${PORTSDIR}/www/py-django16         \
		${PYTHON_PKGNAMEPREFIX}django-tastypie>=0.11.0:${PORTSDIR}/www/py-django-tastypie \
		${PYTHON_PKGNAMEPREFIX}django-tastypie-mongoengine>=0.4.5:${PORTSDIR}/devel/py-django-tastypie-mongoengine \
		${PYTHON_PKGNAMEPREFIX}mongoengine>=0.8.7:${PORTSDIR}/devel/py-mongoengine \
		${PYTHON_PKGNAMEPREFIX}pydeep>=0.2:${PORTSDIR}/security/py-pydeep          \
		${PYTHON_PKGNAMEPREFIX}pefile>=1.2.10.114:${PORTSDIR}/devel/py-pefile      \
		${PYTHON_PKGNAMEPREFIX}yara>=2.1.0:${PORTSDIR}/security/py-yara            \
		${PYTHON_PKGNAMEPREFIX}pynids>=0.6.1:${PORTSDIR}/net/pynids                \
		${PYTHON_PKGNAMEPREFIX}anyjson>=0.3.3:${PORTSDIR}/devel/py-anyjson         \
		${PYTHON_PKGNAMEPREFIX}amqp>=1.0.6:${PORTSDIR}/net/py-amqp                 \
		${PYTHON_PKGNAMEPREFIX}billiard>=2.7.3.19:${PORTSDIR}/devel/py-billiard    \
		${PYTHON_PKGNAMEPREFIX}kombu>=2.5.4:${PORTSDIR}/net/py-kombu               \
		${PYTHON_PKGNAMEPREFIX}celery>=3.0.12:${PORTSDIR}/devel/py-celery          \
		${PYTHON_PKGNAMEPREFIX}requests1>=1.1.0_9:${PORTSDIR}/www/py-requests1     \
		${PKGNAMEPREFIX}pillow>=2.4.0:${PORTSDIR}/graphics/py-pillow               \
		${PYTHON_PKGNAMEPREFIX}parsing>=1.5.1:${PORTSDIR}/devel/py-parsing         \
		${PYTHON_PKGNAMEPREFIX}ldap>=2.4.15:${PORTSDIR}/net/py-ldap                \
		${PYTHON_PKGNAMEPREFIX}magic>0:${PORTSDIR}/devel/py-magic                  \
		${PYTHON_PKGNAMEPREFIX}mimeparse>=0.1.4:${PORTSDIR}/devel/py-mimeparse     \
		${PYTHON_PKGNAMEPREFIX}cybox>=2.1.0.5:${PORTSDIR}/security/py-cybox        \
		${PYTHON_PKGNAMEPREFIX}stix>=1.1.1.0:${PORTSDIR}/security/py-stix          \
		${APACHE_PKGNAMEPREFIX}mod_wsgi3>=3.3:${PORTSDIR}/www/mod_wsgi3            \

NO_BUILD=	YES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
