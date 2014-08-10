# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	pftabled
PORTVERSION=	1.09
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The pftabled is a tool to manage your pf tables remotely

USE_RC_SUBR=	pftabled

PLIST_FILES=	bin/pftabled-client man/man1/pftabled.1.gz sbin/pftabled

GNU_CONFIGURE=	yes
USES=		gmake shebangfix
SHEBANG_FILES=	pftabled-client.pl

OPTIONS_DEFINE=	PERLC PYTHONC
OPTIONS_DEFAULT=	PERLC PYTHONC
PERLC_DESC=	A Sample Perl Client
PYTHONC_DESC=	A Sample Python Client

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPERLC}
PLIST_FILES+=	bin/pftabled-client.pl
.endif

.if ${PORT_OPTIONS:MPYTHONC}
PLIST_FILES+=	bin/pftabled-client.py
.endif

post-install:
.if ${PORT_OPTIONS:MPERLC}
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.pl ${STAGEDIR}${PREFIX}/bin/
.endif
.if ${PORT_OPTIONS:MPYTHONC}
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.py ${STAGEDIR}${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
