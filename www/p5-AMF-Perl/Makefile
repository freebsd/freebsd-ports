# New ports collection makefile for:	Flash-FLAP
# Date created:	   20 May 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	AMF-Perl
PORTVERSION=	0.15
CATEGORIES=	www devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/SI/SIMONF
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Flash Remoting in Perl

PERL_CONFIGURE=	yes

NOMANCOMPRESS=	no
MAN3=		AMF::Perl.3 AMF::Perl::App::Executive.3 \
		AMF::Perl::IO::Deserializer.3 AMF::Perl::IO::InputStream.3 \
		AMF::Perl::IO::OutputStream.3 AMF::Perl::IO::Serializer.3 \
		AMF::Perl::Sql::MysqlRecordSet.3 AMF::Perl::Util::Object.3 \
		AMF::Perl::Util::RemotingService.3

post-patch:
	@${PERL} -pi -e 's/=(?==head)//g' ${WRKSRC}/lib/AMF/Perl.pm

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
