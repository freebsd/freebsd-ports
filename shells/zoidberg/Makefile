# ex:ts=8
# Ports collection makefile for:	zoidberg
# Date created:			Sep 24, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	zoidberg
PORTVERSION=	0.90
CATEGORIES=	shells perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		http://zoidberg.student.utwente.nl/downloads/Zoidberg/
MASTER_SITE_SUBDIR=	Bundle
DISTNAME=	Zoidberg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A modular PERL shell

BUILD_DEPENDS=	${SITE_PERL}/Exporter/Tidy.pm:${PORTSDIR}/devel/p5-Exporter-Tidy \
		${SITE_PERL}/Term/ReadLine/Zoid.pm:${PORTSDIR}/devel/p5-Term-ReadLine-Zoid \
		${SITE_PERL}/Env/PS1.pm:${PORTSDIR}/devel/p5-Env-PS1
RUN_DEPENDS=	${SITE_PERL}/Exporter/Tidy.pm:${PORTSDIR}/devel/p5-Exporter-Tidy \
		${SITE_PERL}/Term/ReadLine/Zoid.pm:${PORTSDIR}/devel/p5-Term-ReadLine-Zoid \
		${SITE_PERL}/Env/PS1.pm:${PORTSDIR}/devel/p5-Env-PS1

PERL_MODBUILD=	yes
CONFIGURE_ARGS=	install_path=doc="${DOCSDIR}" \
		install_path=share="${DATADIR}"

PORTDOCS=	*

MAN1=	zoid.1 zoiddevel.1 zoidfaq.1 zoiduser.1
MAN3=	Bundle::Zoidberg.3 \
	Zoidberg.3 \
	Zoidberg::Contractor.3 \
	Zoidberg::DispatchTable.3 \
	Zoidberg::Eval.3 \
	Zoidberg::Fish.3 \
	Zoidberg::Fish::Commands.3 \
	Zoidberg::Fish::Intel.3 \
	Zoidberg::Fish::Log.3 \
	Zoidberg::Fish::ReadLine.3 \
	Zoidberg::PluginHash.3 \
	Zoidberg::Shell.3 \
	Zoidberg::StringParser.3 \
	Zoidberg::Utils.3 \
	Zoidberg::Utils::Error.3 \
	Zoidberg::Utils::FileSystem.3 \
	Zoidberg::Utils::GetOpt.3 \
	Zoidberg::Utils::Output.3

post-install:
	@${ECHO_CMD} ${PREFIX}/bin/zoid >> /etc/shells

.include <bsd.port.mk>
