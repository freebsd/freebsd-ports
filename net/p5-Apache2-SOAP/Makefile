# New ports collection makefile for:	Apache2-SOAP
# Date Created:				26 January 2006
# Whom:					Simun Mikecin <numisemis@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	Apache2-SOAP
PORTVERSION=	0.72
CATEGORIES=	net www perl5
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/CPAN/authors/id/R/RK/RKOBES/ \
		http://cpan.mirror.solnet.ch/modules/by-module/File/RKOBES/ \
		http://cpan.mirror.fr/modules/by-module/Apache2/ \
		http://backpan.perl.org/authors/id/R/RK/RKOBES/ \
		http://cpan.mirrorgeek.com/modules/by-category/10_File_Names_Systems_Locking/File/RKOBES/ \
		http://cpan.stu.edu.tw/modules/by-category/15_World_Wide_Web_HTML_HTTP_CGI/Apache2/
MASTER_SITE_SUBDIR=	Apache2
PKGNAMEPREFIX=	p5-

MAINTAINER=	numisemis@yahoo.com
COMMENT=	Apache2 mod_perl2 SOAP Server

PERL_CONFIGURE=	5.8.0+
USE_APACHE=	2.0+

MAN3=		Apache2::SOAP.3

BUILD_DEPENDS=	${LOCALBASE}/${APACHEMODDIR}/mod_perl.so:${PORTSDIR}/www/mod_perl2
BUILD_DEPENDS+=	${SITE_PERL}/SOAP/Lite.pm:${PORTSDIR}/net/p5-SOAP-Lite
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.mk>
