# Created by: Maxim Ignatenko <gelraen.ua@gmail.com>
# $FreeBSD$

PORTNAME=	eiskaltdcpp
PORTREVISION=	20
CATEGORIES=	net-p2p
PKGNAMESUFFIX=	-cli

MAINTAINER=	ports@FreeBSD.org
COMMENT=	EiskaltDC++ client command-line interface

LICENSE=	GPLv3

RUN_DEPENDS=	p5-RPC-XML>=0:net/p5-RPC-XML \
		p5-JSON-RPC>=0:devel/p5-JSON-RPC \
		p5-Term-ShellUI>=0:shells/p5-Term-ShellUI

MASTERDIR=	${.CURDIR}/../eiskaltdcpp-lib

NO_BUILD=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	eiskaltdcpp-cli/*.pl

do-install:
	@${INSTALL_SCRIPT} "${WRKSRC}/eiskaltdcpp-cli/cli-jsonrpc.pl" \
		"${STAGEDIR}${PREFIX}/bin/eiskaltdcpp-cli-jsonrpc"
	@${INSTALL_SCRIPT} "${WRKSRC}/eiskaltdcpp-cli/cli-xmlrpc.pl" \
		"${STAGEDIR}${PREFIX}/bin/eiskaltdcpp-cli-xmlrpc"
	@${INSTALL_MAN} "${WRKSRC}/eiskaltdcpp-cli/eiskaltdcpp-cli-jsonrpc.1" \
		"${STAGEDIR}${PREFIX}/man/man1/"
	@${INSTALL_MAN} "${WRKSRC}/eiskaltdcpp-cli/eiskaltdcpp-cli-xmlrpc.1" \
		"${STAGEDIR}${PREFIX}/man/man1/"
	@${MKDIR} "${STAGEDIR}${PREFIX}/etc/eiskaltdcpp" || true
	@${INSTALL_DATA} "${WRKSRC}/eiskaltdcpp-cli/cli-jsonrpc-config.pl" \
		"${STAGEDIR}${PREFIX}/etc/eiskaltdcpp/cli-jsonrpc-config.pl.sample"
	@${INSTALL_DATA} "${WRKSRC}/eiskaltdcpp-cli/cli-xmlrpc-config.pl" \
		"${STAGEDIR}${PREFIX}/etc/eiskaltdcpp/cli-xmlrpc-config.pl.sample"

.include "${MASTERDIR}/Makefile"
