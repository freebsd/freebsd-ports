# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	XML-DBMS
PORTVERSION=	1.03
PORTREVISION=	1
CATEGORIES=	textproc databases perl5
MASTER_SITES=	http://www.rpbourret.com/xmldbms/
PKGNAMEPREFIX=	p5-
DISTNAME=	perl-${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Perl port of Java package XML-DBMS v1.0

BUILD_DEPENDS=	p5-libxml>=0:textproc/p5-libxml \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-DBI>=0:databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}
USES=		dos2unix perl5 tar:tgz
USE_PERL5=	configure

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/*.* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
