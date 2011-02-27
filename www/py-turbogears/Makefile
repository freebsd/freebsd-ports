# New ports collection makefile for:	turbogears
# Date created:		2006-01-08
# Whom:			Nicola Vitale	<nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboGears
PORTVERSION=	1.1.2
CATEGORIES=	www python
MASTER_SITES=	http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Python-Based Framework for Rapid Web Development

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cherrypy-old>=2.3.0:${PORTSDIR}/www/py-cherrypy-old \
		${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}formencode>=1.2.1:${PORTSDIR}/www/py-formencode \
		${PYTHON_PKGNAMEPREFIX}PasteScript>=1.7.3:${PORTSDIR}/www/py-pastescript \
		${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0.5a1:${PORTSDIR}/devel/py-PEAK-Rules \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}TurboCheetah>=1.0:${PORTSDIR}/devel/py-turbocheetah \
		${PYTHON_PKGNAMEPREFIX}TurboKid>=1.0.5:${PORTSDIR}/devel/py-turbokid \
		${PYTHON_PKGNAMEPREFIX}TurboJson>=1.3:${PORTSDIR}/devel/py-turbojson \
		${PYTHON_PKGNAMEPREFIX}tgMochiKit>=1.4.2:${PORTSDIR}/devel/py-tgMochiKit \
		${PYTHON_PKGNAMEPREFIX}Genshi>=0.4.4:${PORTSDIR}/textproc/py-genshi

USE_GETTEXT=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS+=	ELIXIR	"Use Elixir as plugin" off \
		NOSE	"Use nose TG[testtools]" off \
		SQLOBJECT	"Use SQLObject as DB backend" on \
		SQLALCHEMY	"Use SQLAlchemy as DB backend TG[future]" off

.include <bsd.port.pre.mk>

.if defined (WITH_ELIXIR)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}Elixir>=0.6.1:${PORTSDIR}/databases/py-Elixir
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
