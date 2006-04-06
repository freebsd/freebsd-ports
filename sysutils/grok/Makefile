# Ports collection makefile for:  grok
# Date created:			  07 March 2006
# Whom:				  Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	grok
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.semicomplete.com/projects/grok/

MAINTAINER=	wxs@csh.rit.edu
COMMENT=	An expert system for real-time log analysis

RUN_DEPENDS=	${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent \
		${SITE_PERL}/${PERL_ARCH}/Unix/Syslog.pm:${PORTSDIR}/sysutils/p5-Unix-Syslog \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate

USE_PERL5=	yes
USE_RC_SUBR=	grok.sh
NO_BUILD=	yes

SUB_FILES=	pkg-message
SUB_LIST=	PERL=${PERL}

MAN1=	grok.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/grok ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/grok.conf ${PREFIX}/etc/grok.conf.sample
	${INSTALL_MAN} ${WRKSRC}/grok.1 ${PREFIX}/man/man1

post-install:
	@if [ ! -f ${PREFIX}/etc/grok.conf ]; then \
		${CP} -p ${PREFIX}/etc/grok.conf.sample ${PREFIX}/etc/grok.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
