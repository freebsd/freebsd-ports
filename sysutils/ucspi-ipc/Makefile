# New ports collection makefile for:	ucspi-ipc
# Date created:		2004-07-07
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	ucspi-ipc
PORTVERSION=	0.63
CATEGORIES=	sysutils
MASTER_SITES=	http://www.superscript.com/ucspi-ipc/

MAINTAINER=	lx@redundancy.redundancy.org
COMMENT=	UCSPI tools for building local-domain client-server applications

USE_PERL5=	yes

DISABLE_SIZE=	yes

NO_PACKAGE=	Non-explicit licensing terms

DOCS=		CHANGES

WRKSRC=		${WRKDIR}/host/superscript.com/net/${DISTNAME}

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	"requires Perl 5.6.0 or greater. Please install lang/perl5 and retry"
.endif

do-build:
	cd ${WRKSRC} && package/compile

do-install:
.for x in ipccat ipcconnect ipcdo ipcrun
	${INSTALL_SCRIPT} ${WRKSRC}/command/${x} ${PREFIX}/bin
.endfor
.for x in ipcclient ipccommand ipcconnect-io ipcexec ipcexec-config \
	ipcexecrules ipcexecrulescheck ipcperl ipcrules ipcrulescheck ipcserver
	${INSTALL_PROGRAM} ${WRKSRC}/command/${x} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/src && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
