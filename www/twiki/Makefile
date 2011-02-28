# Ports collection makefile for:	TWiki
# Date created:			Fri Mar  7 14:36:05 CST 2003
# Whom:				Justin Hawkins <justin@hawkins.id.au>
#
# $FreeBSD$
#

PORTNAME=	twiki
PORTVERSION=	4.2.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://twiki.org/p/pub/Codev/Release/ \
		GENTOO/distfiles
DISTNAME=	TWiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible, powerful, and easy to use enterprise wiki

RUN_DEPENDS=	\
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-Error>=0:${PORTSDIR}/lang/p5-Error \
		p5-Text-Diff>=0:${PORTSDIR}/textproc/p5-Text-Diff \
		p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Locale-Maketext-Lexicon>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Lexicon \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		twiki-TWikiUserMappingContrib>=0:${PORTSDIR}/www/twiki-TWikiUserMappingContrib

USE_PERL5=	yes

post-extract:
	@cd ${WRKDIR}/ && ${INSTALL} -d .t/ && ${MV} * .t/ && ${MV} .t ${WRKSRC}
	@${RM} -rf ${WRKSRC}/lib/CPAN
	@${CAT} ${.CURDIR}/../twiki-*/pkg-plist |\
		${SED} -e 's|%%TWDIR%%|${WRKSRC}|;/^@/d' |\
		${XARGS} ${RM} -f
	@${FIND} ${WRKSRC} -name \*,v | while read f; do\
		[ -e $${f%%,v} ] || ${RM} -f $$f; done
	@${FIND} ${WRKSRC} -type d -empty -delete

post-patch:
	@cd ${WRKSRC}/ &&\
		${REINPLACE_CMD} -i "" -e "s|/home/httpd/twiki|${WWWDIR}|g" \
		lib/TWiki.spec twiki_httpd_conf.txt
	@${FIND} ${WRKSRC} -name \*.orig -delete

.include "${.CURDIR}/bsd.twiki.mk"
.include <bsd.port.mk>
