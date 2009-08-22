# ex:ts=8
# Ports collection makefile for:	denature
# Date created:			Jan 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	denature
PORTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A HTML to PDF converter

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/HTML/Tagset.pm:${PORTSDIR}/www/p5-HTML-Tagset \
		${SITE_PERL}/HTML/Tree.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/CSS/Tiny.pm:${PORTSDIR}/textproc/p5-CSS-Tiny \
		fop:${PORTSDIR}/textproc/fop

USE_PERL5=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.2+
POD2MAN?=	pod2man
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		denature.1
PLIST_FILES=	bin/denature

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}| ; \
		s|%%JAVA_HOME%%|${JAVA_HOME}|" ${WRKSRC}/denature

do-build:
	cd ${WRKSRC} && ${POD2MAN} denature > denature.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/denature ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/denature.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
