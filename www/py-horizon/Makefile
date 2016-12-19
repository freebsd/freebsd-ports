# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	horizon
PORTVERSION=	10.0.1
CATEGORIES=	www python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Dashboard (Horizon)

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}django18>=0:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}Pint>=0.5:devel/py-Pint \
		${PYTHON_PKGNAMEPREFIX}django-babel>=0.5.1:www/py-django-babel \
		${PYTHON_PKGNAMEPREFIX}django_compressor>=2.0:www/py-django_compressor \
		${PYTHON_PKGNAMEPREFIX}django_openstack_auth>=2.4.0:www/py-django_openstack_auth \
		${PYTHON_PKGNAMEPREFIX}django-pyscss>=2.0.2:www/py-django-pyscss \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}pyscss>=1.3.4:textproc/py-pyscss \
		${PYTHON_PKGNAMEPREFIX}python-ceilometerclient>=2.5.0:net/py-python-ceilometerclient \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=0:net/py-python-cinderclient \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=0:net/py-python-glanceclient \
		${PYTHON_PKGNAMEPREFIX}python-heatclient>=1.4.0:net/py-python-heatclient \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=0:net/py-python-keystoneclient \
		${PYTHON_PKGNAMEPREFIX}python-neutronclient>=5.1.0:net/py-python-neutronclient \
		${PYTHON_PKGNAMEPREFIX}python-novaclient>=0:net/py-python-novaclient \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=2.2.0:databases/py-python-swiftclient \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.1.0:devel/py-yaml \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}XStatic>=1.0.0:devel/py-XStatic \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular>=1.3.7:devel/py-XStatic-Angular \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Bootstrap>=0.11.0.2:devel/py-XStatic-Angular-Bootstrap \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-FileUpload>=12.0.4.0:devel/py-XStatic-Angular-FileUpload \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Gettext>=2.1.0.2:devel/py-XStatic-Angular-Gettext \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-lrdragndrop>=1.0.2.2:devel/py-XStatic-Angular-lrdragndrop \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Schema-Form>=0.8.13.0:devel/py-XStatic-Angular-Schema-Form \
		${PYTHON_PKGNAMEPREFIX}XStatic-Bootstrap-Datepicker>=1.3.1.0:devel/py-XStatic-Bootstrap-Datepicker \
		${PYTHON_PKGNAMEPREFIX}XStatic-Bootstrap-SCSS>=3:devel/py-XStatic-Bootstrap-SCSS \
		${PYTHON_PKGNAMEPREFIX}XStatic-bootswatch>=3.3.5.3:devel/py-XStatic-bootswatch \
		${PYTHON_PKGNAMEPREFIX}XStatic-D3>=3.1.6.2:devel/py-XStatic-D3 \
		${PYTHON_PKGNAMEPREFIX}XStatic-Hogan>=2.0.0.2:devel/py-XStatic-Hogan \
		${PYTHON_PKGNAMEPREFIX}XStatic-Font-Awesome>=4.3.0:devel/py-XStatic-Font-Awesome \
		${PYTHON_PKGNAMEPREFIX}XStatic-Jasmine>=2.1.2.0:devel/py-XStatic-Jasmine \
		${PYTHON_PKGNAMEPREFIX}XStatic-jQuery>=1.7.2:devel/py-XStatic-jQuery \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery-Migrate>=1.2.1.1:devel/py-XStatic-JQuery-Migrate \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery.quicksearch>=2.0.3.1:devel/py-XStatic-JQuery.quicksearch \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery.TableSorter>=2.14.5.1:devel/py-XStatic-JQuery.TableSorter \
		${PYTHON_PKGNAMEPREFIX}XStatic-jquery-ui>=1.10.1:devel/py-XStatic-jquery-ui \
		${PYTHON_PKGNAMEPREFIX}XStatic-JSEncrypt>=2.0.0.2:devel/py-XStatic-JSEncrypt \
		${PYTHON_PKGNAMEPREFIX}XStatic-mdi>=1.4.57.0:devel/py-XStatic-mdi \
		${PYTHON_PKGNAMEPREFIX}XStatic-objectpath>=1.2.1.0:devel/py-XStatic-objectpath \
		${PYTHON_PKGNAMEPREFIX}XStatic-Rickshaw>=1.5.0:devel/py-XStatic-Rickshaw \
		${PYTHON_PKGNAMEPREFIX}XStatic-roboto-fontface>=0.4.3.2:devel/py-XStatic-roboto-fontface \
		${PYTHON_PKGNAMEPREFIX}XStatic-smart-table>=0:devel/py-XStatic-smart-table \
		${PYTHON_PKGNAMEPREFIX}XStatic-Spin>=1.2.5.2:devel/py-XStatic-Spin \
		${PYTHON_PKGNAMEPREFIX}XStatic-term.js>=0.0.4:devel/py-XStatic-term.js \
		${PYTHON_PKGNAMEPREFIX}XStatic-tv4>=1.2.7.0:devel/py-XStatic-tv4

EXTRA_PATCHES=	 ${FILESDIR}/01-django.patch:-p1

NO_ARCH=	yes

USES=		python
USE_PYTHON=	autoplist distutils

USERS=		horizon
GROUPS=		horizon

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
