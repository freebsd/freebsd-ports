# New ports collection makefile for:	XML::DBMS
# Date created:		18 Dec 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	XML-DBMS
PORTVERSION=	1.03
CATEGORIES=	textproc databases perl5
MASTER_SITES=	ftp://ftp.rpbourret.com/
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-xml-dbms-1.03
EXTRACT_SUFX=	.tgz

MAINTAINER=	skv@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/Parser/PerlSAX.pm:${PORTSDIR}/textproc/p5-libxml \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_SUB=	EXAMPLESDIR="share/examples/${PORTNAME}"
WRKSRC=		${WRKDIR}/${PORTNAME}
PERL_CONFIGURE=	yes

post-extract:
	@${FIND} ${WRKSRC} -type f | \
		xargs ${PERL} -pi -e 's/\x0D(?=\x0A)//g'

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
