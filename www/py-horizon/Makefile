# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	horizon
PORTVERSION=	10.0.1
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Dashboard (Horizon)

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django18>=0:www/py-django18@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pint>=0.5:devel/py-Pint@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-babel>=0.5.1:www/py-django-babel@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django_compressor>=2.0:www/py-django_compressor@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django_openstack_auth>=2.4.0:www/py-django_openstack_auth@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pyscss>=2.0.2:www/py-django-pyscss@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscss>=1.3.4:textproc/py-pyscss@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ceilometerclient>=2.5.0:net/py-python-ceilometerclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=0:net/py-python-cinderclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=0:net/py-python-glanceclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-heatclient>=1.4.0:net/py-python-heatclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=0:net/py-python-keystoneclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-neutronclient>=5.1.0:net/py-python-neutronclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-novaclient>=0:net/py-python-novaclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=2.2.0:databases/py-python-swiftclient@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.1.0:devel/py-yaml@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic>=1.0.0:devel/py-XStatic@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular>=1.3.7:devel/py-XStatic-Angular@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Bootstrap>=0.11.0.2:devel/py-XStatic-Angular-Bootstrap@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-FileUpload>=12.0.4.0:devel/py-XStatic-Angular-FileUpload@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Gettext>=2.1.0.2:devel/py-XStatic-Angular-Gettext@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-lrdragndrop>=1.0.2.2:devel/py-XStatic-Angular-lrdragndrop@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Schema-Form>=0.8.13.0:devel/py-XStatic-Angular-Schema-Form@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Bootstrap-Datepicker>=1.3.1.0:devel/py-XStatic-Bootstrap-Datepicker@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Bootstrap-SCSS>=3:devel/py-XStatic-Bootstrap-SCSS@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-bootswatch>=3.3.5.3:devel/py-XStatic-bootswatch@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-D3>=3.1.6.2:devel/py-XStatic-D3@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Hogan>=2.0.0.2:devel/py-XStatic-Hogan@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Font-Awesome>=4.3.0:devel/py-XStatic-Font-Awesome@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Jasmine>=2.1.2.0:devel/py-XStatic-Jasmine@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-jQuery>=1.7.2:devel/py-XStatic-jQuery@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery-Migrate>=1.2.1.1:devel/py-XStatic-JQuery-Migrate@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery.quicksearch>=2.0.3.1:devel/py-XStatic-JQuery.quicksearch@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery.TableSorter>=2.14.5.1:devel/py-XStatic-JQuery.TableSorter@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-jquery-ui>=1.10.1:devel/py-XStatic-jquery-ui@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JSEncrypt>=2.0.0.2:devel/py-XStatic-JSEncrypt@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-mdi>=1.4.57.0:devel/py-XStatic-mdi@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-objectpath>=1.2.1.0:devel/py-XStatic-objectpath@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Rickshaw>=1.5.0:devel/py-XStatic-Rickshaw@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-roboto-fontface>=0.4.3.2:devel/py-XStatic-roboto-fontface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-smart-table>=0:devel/py-XStatic-smart-table@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Spin>=1.2.5.2:devel/py-XStatic-Spin@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-term.js>=0.0.4:devel/py-XStatic-term.js@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-tv4>=1.2.7.0:devel/py-XStatic-tv4@${FLAVOR}

EXTRA_PATCHES=	${FILESDIR}/01-django.patch:-p1 \
		${FILESDIR}/02-fix-floating-ips.patch:-p1

NO_ARCH=	yes

USES=		python:2.7
USE_PYTHON=	autoplist distutils

USERS=		horizon
GROUPS=		horizon

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
