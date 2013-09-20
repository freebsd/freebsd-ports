# Created by: Bartlomiej Rutkowski <r@robakdesign.com>
# $FreeBSD$

PORTNAME=	pftabled
PORTVERSION=	1.09
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	chifeng@gmail.com
COMMENT=	The pftabled is a tool to manage your pf tables remotely

USE_RC_SUBR=	pftabled
MAN1=		pftabled.0

PLIST_FILES=	bin/pftabled-client sbin/pftabled

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS_DEFINE=	PERLC PYTHONC
OPTIONS_DEFAULT=	PERLC PYTHONC
PERLC_DESC=	A Sample Perl Client
PYTHONC_DESC=	A Sample Python Client

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPERLC}
PLIST_FILES+=	bin/pftabled-client.pl
.endif

.if ${PORT_OPTIONS:MPYTHONC}
PLIST_FILES+=	bin/pftabled-client.py
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|cat1/pftabled.0|man1/pftabled.0|' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MPERLC}
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.pl ${PREFIX}/bin/
.endif
.if ${PORT_OPTIONS:MPYTHONC}
	${INSTALL_SCRIPT} ${WRKSRC}/pftabled-client.py ${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
