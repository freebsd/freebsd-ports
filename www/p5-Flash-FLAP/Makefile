# New ports collection makefile for:	Flash-FLAP
# Date created:	   20 May 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Flash-FLAP
PORTVERSION=	0.08
CATEGORIES=	www devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Flash
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Flash Remoting in Perl

PERL_CONFIGURE=	yes

MAN3=		Flash::FLAP.3 Flash::FLAP::App::Executive.3 \
		Flash::FLAP::IO::Deserializer.3 Flash::FLAP::IO::InputStream.3 \
		Flash::FLAP::IO::OutputStream.3 Flash::FLAP::IO::Serializer.3 \
		Flash::FLAP::Sql::MysqlRecordSet.3 Flash::FLAP::Util::Object.3 \
		Flash::FLAP::Util::RemotingService.3

post-configure:
# dirty hack to deceive irritable pod2man
	@${PERL} -pi -e 's/^(POD2MAN_EXE.*)$$/\1 --lax/;' ${WRKSRC}/Makefile

.include <bsd.port.mk>
