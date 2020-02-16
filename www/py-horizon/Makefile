# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	horizon
PORTVERSION=	13.0.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	https://tarballs.openstack.org/horizon/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack Dashboard (Horizon)

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=2.0.0:devel/py-pbr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django111>=1.8:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Pint>=0.5:devel/py-Pint@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-babel>=0.5.1:www/py-django-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django_compressor>=2.0:www/py-django_compressor@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pyscss>=2.0.2:www/py-django-pyscss@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}futurist>=1.2.0:devel/py-futurist@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=3.3.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.18:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.25.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=5.1.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=3.15.3:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=2.18.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.33.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}osprofiler>=1.4.0:devel/py-osprofiler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>=3.0.2:databases/pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyscss>=1.3.4:textproc/py-pyscss@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=2.8.0:net/py-python-glanceclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-keystoneclient>=3.8.0:net/py-python-keystoneclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-neutronclient>=6.3.0:net/py-python-neutronclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-novaclient>=9.1.0:net/py-python-novaclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-swiftclient>=3.2.0:databases/py-python-swiftclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2013.6:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=3.10.0:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}semantic_version>=2.3.1:devel/py-semantic_version@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.10.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic>=1.0.0:devel/py-XStatic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular>=1.5.8.0:devel/py-XStatic-Angular@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Bootstrap>=2.2.0.0:devel/py-XStatic-Angular-Bootstrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-FileUpload>=12.0.4.0:devel/py-XStatic-Angular-FileUpload@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Gettext>=2.3.8.0:devel/py-XStatic-Angular-Gettext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-lrdragndrop>=1.0.2.2:devel/py-XStatic-Angular-lrdragndrop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Angular-Schema-Form>=0.8.13.0:devel/py-XStatic-Angular-Schema-Form@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Bootstrap-Datepicker>=1.3.1.0:devel/py-XStatic-Bootstrap-Datepicker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Bootstrap-SCSS>=3.3.7.1:devel/py-XStatic-Bootstrap-SCSS@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-bootswatch>=3.3.7.0:devel/py-XStatic-bootswatch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-D3>=3.5.17.0:devel/py-XStatic-D3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Hogan>=2.0.0.2:devel/py-XStatic-Hogan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Font-Awesome>=4.7.0.0:devel/py-XStatic-Font-Awesome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Jasmine>=2.4.1.1:devel/py-XStatic-Jasmine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-jQuery>=1.8.2.1:devel/py-XStatic-jQuery@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery-Migrate>=1.2.1.1:devel/py-XStatic-JQuery-Migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery.quicksearch>=2.0.3.1:devel/py-XStatic-JQuery.quicksearch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JQuery.TableSorter>=2.14.5.1:devel/py-XStatic-JQuery.TableSorter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-jquery-ui>=1.10.4.1:devel/py-XStatic-jquery-ui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-JSEncrypt>=2.3.1.1:devel/py-XStatic-JSEncrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-mdi>=1.4.57.0:devel/py-XStatic-mdi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-objectpath>=1.2.1.0:devel/py-XStatic-objectpath@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Rickshaw>=1.5.0.0:devel/py-XStatic-Rickshaw@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-roboto-fontface>=0.5.0.0:devel/py-XStatic-roboto-fontface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-smart-table>=1.4.13.2:devel/py-XStatic-smart-table@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-Spin>=1.2.5.2:devel/py-XStatic-Spin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-term.js>=0.0.7.0:devel/py-XStatic-term.js@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XStatic-tv4>=1.2.7.0:devel/py-XStatic-tv4@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

USERS=		horizon
GROUPS=		horizon

SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

CONFLICTS_INSTALL=	py??-horizon-*

post-patch:
	@${REINPLACE_CMD} -Ee 's|(pyScss)!=1.3.5,|\1|' ${WRKSRC}/requirements.txt

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 3600
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.policy2>=1.30.0:devel/py-oslo.policy2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient5>=3.3.0:net/py-python-cinderclient5@${PY_FLAVOR}
.else
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.30.0:devel/py-oslo.policy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=3.3.0:net/py-python-cinderclient@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
