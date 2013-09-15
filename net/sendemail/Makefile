# New ports collection makefile for:	sendEmail
# Date created:				2005-12-17
# Whom:			Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
#

PORTNAME=	sendEmail
PORTVERSION=	1.56
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://caspian.dotconf.net/menu/Software/SendEmail/ \
		http://T32.TecNik93.com/FreeBSD/ports/${PORTNAME}/sources/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	itetcu@FreeBSD.org
COMMENT=	Lightweight, completely command line based, SMTP email agent

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

PLIST_FILES=	bin/sendEmail
PORTDOCS=	CHANGELOG README TODO

OPTIONS_DEFINE=	SSL
OPTIONS_DEFINE=	DOCS
SSL_DESC=	SSL/TLS support for communicating with the SMTP server

.include <bsd.port.pre.mk>
.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS+=	p5-Crypt-SSLeay>=0:${PORTSDIR}/security/p5-Crypt-SSLeay
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/usr/bin/perl,${PERL},g" \
		${WRKSRC}/${PORTNAME}

do-install:
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ${PORTNAME} ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG README TODO ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
