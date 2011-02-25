# New ports collection makefile for:	turbogears
# Date created:		2006-01-08
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboGears
PORTVERSION=	1.0.8
PORTREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python-Based Framework for Rapid Web Development

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy-old>=2.3:${PORTSDIR}/www/py-cherrypy-old \
		${PYTHON_PKGNAMEPREFIX}configobj>=4.5.3:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}formencode>=0.6_1:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7.3:${PORTSDIR}/www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}RuleDispatch>=0.5.a0.r2303:${PORTSDIR}/devel/py-ruledispatch \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.4:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}TurboCheetah>=1.0:${PORTSDIR}/devel/py-turbocheetah \
		${PYTHON_PKGNAMEPREFIX}TurboKid>=1.0.4:${PORTSDIR}/devel/py-turbokid \
		${PYTHON_PKGNAMEPREFIX}TurboJson>=1.1.4:${PORTSDIR}/devel/py-turbojson11

USE_GETTEXT=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS+=	ELIXIR	"Use Elixir as plugin" off \
		GENSHI	"Use Genshi as plugin TG[future]" off \
		NOSE	"Use nose TG[testtools]" off \
		SQLOBJECT	"Use SQLObject as DB backend" on \
		SQLALCHEMY	"Use SQLAlchemy as DB backend TG[future]" off

.include <bsd.port.pre.mk>

.if defined (WITH_ELIXIR)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Elixir>=0.6.1:${PORTSDIR}/databases/py-Elixir
.endif

.if defined (WITH_GENSHI)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Genshi>=0.3.6:${PORTSDIR}/textproc/py-genshi
.endif

.if defined (WITH_NOSE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>=0.9.1:${PORTSDIR}/devel/py-nose
.endif

.if defined (WITH_SQLOBJECT)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlobject>=0.10.1:${PORTSDIR}/databases/py-sqlobject
.endif

.if defined (WITH_SQLALCHEMY)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.3.4:${PORTSDIR}/databases/py-sqlalchemy
.endif

.include <bsd.port.post.mk>
