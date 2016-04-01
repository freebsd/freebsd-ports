# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	TurboGears
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python-Based Framework for Rapid Web Development

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy>=3.1.2:www/py-cherrypy \
		${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.1:www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7:www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0.5a1:devel/py-PEAK-Rules \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}TurboCheetah>=1.0:devel/py-turbocheetah \
		${PYTHON_PKGNAMEPREFIX}TurboKid>=1.0.5:devel/py-turbokid \
		${PYTHON_PKGNAMEPREFIX}TurboJson>=1.3:devel/py-turbojson \
		${PYTHON_PKGNAMEPREFIX}tgMochiKit>=1.4.2:devel/py-tgMochiKit \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.4.4:textproc/py-genshi \
		${PYTHON_PKGNAMEPREFIX}TGScheduler>0:devel/py-TGScheduler

USES=		gettext python:2
USE_PYTHON=	distutils autoplist

OPTIONS_DEFINE=	ELIXIR NOSE SQLOBJECT SQLALCHEMY
OPTIONS_DEFAULT=SQLOBJECT
ELIXIR_DESC=	Use Elixir as plugin
NOSE_DESC=	Use nose TG[testtools]
SQLOBJECT_DESC=	Use SQLObject as DB backend
SQLALCHEMY_DESC=Use SQLAlchemy as DB backend TG[future]

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,< 2.0a,!=2.0,g' ${WRKSRC}/setup.py \
		${WRKSRC}/TurboGears.egg-info/requires.txt

.if ${PORT_OPTIONS:MELIXIR}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Elixir>=0.6.1:databases/py-Elixir
.endif

.if ${PORT_OPTIONS:MNOSE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>=0.9.1:devel/py-nose
.endif

.if ${PORT_OPTIONS:MSQLOBJECT}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlobject>=0.10.1:databases/py-sqlobject
.endif

.if ${PORT_OPTIONS:MSQLALCHEMY}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.3.4:databases/py-sqlalchemy06
.endif

.include <bsd.port.mk>
