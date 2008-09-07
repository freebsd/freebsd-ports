# New ports collection makefile for:	docdiff
# Date created:		13 December 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	docdiff
PORTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compare text word by word

RUN_DEPENDS=	*ruby*-uconv>=0:${PORTSDIR}/japanese/ruby-uconv \
		*ruby*-iconv>=0:${PORTSDIR}/converters/ruby-iconv

USE_RUBY=	yes
NO_BUILD=	yes
PORTDOCS=	readme.html readme.en.html readme.ja.html

post-patch:
	@${REINPLACE_CMD} -e '1s|#!.*|#!${RUBY}|;/ :format/s|html|tty|;\
	/SystemConfigFileName =/s|etc.*conf|${PREFIX}/etc/${PORTNAME}.conf|;\
	s|/etc/docdiff/docdiff.conf|${PREFIX}/etc/${PORTNAME}.conf|'\
		${WRKSRC}/${PORTNAME}.rb

do-install:
	@cd ${WRKSRC}/${PORTNAME}/&&\
		${COPYTREE_SHARE} . ${RUBY_SITELIBDIR}/${PORTNAME}/
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.rb ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.example ${PREFIX}/etc/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
