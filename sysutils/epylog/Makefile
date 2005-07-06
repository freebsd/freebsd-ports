# New ports collection makefile for:	epylog
# Date created:				3 July 2005
# Whom:					Alan Snelson <alan@wave2.co.uk>
#
# $FreeBSD$
#

PORTNAME=	epylog
PORTVERSION=	1.0.3
CATEGORIES=	sysutils
MASTER_SITES=	http://linux.duke.edu/projects/epylog/download/

MAINTAINER=	alan@wave2.co.uk
COMMENT=	Epylog is a syslog parser which mails you the output

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

MAN3=		epylog.3
MAN5=		epylog-modules.5 epylog.conf.5
MAN8=		epylog.8

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lynx --prefix=${PREFIX}
USE_PERL5=	yes
USE_PYTHON=	yes

.include <bsd.port.mk>
