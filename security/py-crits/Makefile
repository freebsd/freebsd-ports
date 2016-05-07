# Created by: Dan Langille <dvl@FreeBSD.org>
# $FreeBSD$

PORTNAME=		crits
PORTVERSION=		3.1.0
PORTREVISION=		3
DISTVERSIONPREFIX=	v
CATEGORIES=		security
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}

MAINTAINER=		dvl@FreeBSD.org
COMMENT=		Collaborative Research Into Threats

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

USE_GITHUB=		yes

USES=			python
USE_PYTHON=		autoplist

USE_APACHE_RUN=	22+

LIB_DEPENDS+=	libpcre.so:devel/pcre  \
		libcurl.so:ftp/curl    \
		libpcap.so:net/libpcap

RUN_DEPENDS+=	7z:archivers/p7zip     \
		unrar:archivers/unrar  \
		upx:archivers/upx	   \
		zip:archivers/zip	   \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:devel/py-simplejson  \
		${PYTHON_PKGNAMEPREFIX}pycurl>0:ftp/py-pycurl             \
		${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot         \
		${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml               \
		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:devel/py-setuptools${PYTHON_SUFFIX} \
		${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy                   \
		${PYTHON_PKGNAMEPREFIX}matplotlib>0:math/py-matplotlib         \
		${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml                    \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.2:devel/py-dateutil         \
		${PYTHON_PKGNAMEPREFIX}m2crypto>0:security/py-m2crypto         \
		mongodb>2.6.4:databases/mongodb                                \
		${PYTHON_PKGNAMEPREFIX}pymongo>=2.7.1:databases/pymongo        \
		${PYTHON_PKGNAMEPREFIX}defusedxml>=0.4.1:devel/py-defusedxml   \
		${PYTHON_PKGNAMEPREFIX}django16>=1.6.5:www/py-django16         \
		${PYTHON_PKGNAMEPREFIX}django-tastypie16>0:www/py-django16-tastypie \
		${PYTHON_PKGNAMEPREFIX}django-tastypie-mongoengine16>=0.4.5:devel/py-django16-tastypie-mongoengine \
		${PYTHON_PKGNAMEPREFIX}mongoengine>=0.8.7:devel/py-mongoengine \
		${PYTHON_PKGNAMEPREFIX}pydeep>=0.2:security/py-pydeep          \
		${PYTHON_PKGNAMEPREFIX}pefile>=1.2.10.114:devel/py-pefile      \
		${PYTHON_PKGNAMEPREFIX}yara>=2.1.0:security/py-yara            \
		${PYTHON_PKGNAMEPREFIX}pynids>=0.6.1:net/pynids                \
		${PYTHON_PKGNAMEPREFIX}anyjson>=0.3.3:devel/py-anyjson         \
		${PYTHON_PKGNAMEPREFIX}amqp>=1.0.6:net/py-amqp                 \
		${PYTHON_PKGNAMEPREFIX}billiard>=2.7.3.19:devel/py-billiard    \
		${PYTHON_PKGNAMEPREFIX}kombu>=2.5.4:net/py-kombu               \
		${PYTHON_PKGNAMEPREFIX}celery>=3.0.12:devel/py-celery          \
		${PYTHON_PKGNAMEPREFIX}requests1>=1.1.0_9:www/py-requests1     \
		${PKGNAMEPREFIX}pillow>=2.4.0:graphics/py-pillow               \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=1.5.1:devel/py-pyparsing     \
		${PYTHON_PKGNAMEPREFIX}ldap>=2.4.15:net/py-ldap                \
		${PYTHON_PKGNAMEPREFIX}magic>0:devel/py-magic                  \
		${PYTHON_PKGNAMEPREFIX}mimeparse>=0.1.4:devel/py-mimeparse     \
		${PYTHON_PKGNAMEPREFIX}cybox>=2.1.0.5:security/py-cybox        \
		${PYTHON_PKGNAMEPREFIX}stix>=1.1.1.0:security/py-stix          \
		${APACHE_PKGNAMEPREFIX}mod_wsgi4>=4.4.13:www/mod_wsgi4

NO_BUILD=	YES

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
