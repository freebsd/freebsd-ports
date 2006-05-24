# New ports collection makefile for:    FDclone
# Date created:         20 Feb 1996
# Whom:                 Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	fd
PORTVERSION=	2.08c
CATEGORIES=	shells
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/ \
		ftp://ftp.unixusers.net/src/fdclone/
#		ftp://ftp.vector.co.jp/pack/unix/util/file/filer/fd/
DISTNAME=	FD-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A CUI-based file and directory management tool

MANLANG=	"" ja
MAN1=		fd.1 fdsh.1
MAKE_ENV=	LANG=ja
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" CONFDIR="${PREFIX}/etc"

DOCS_EN=	FAQ.eng \
		LICENSES.eng \
		README.eng \
		TECHKNOW.eng \
		ToAdmin.eng
DOCS_JA=	FAQ \
		HISTORY \
		LICENSES \
		README \
		TECHKNOW \
		ToAdmin

post-patch:
	${REINPLACE_CMD} -E -e 's|^(#define[[:space:]]+EXTENDCCOPT[[:space:]]+)"-O"$$|\1 "${CFLAGS}"|' ${WRKSRC}/machine.h

post-install:
	@${ECHO} "Updating /etc/shells"
	@-${CP} /etc/shells /etc/shells.bak; \
		(${GREP} -v ${PREFIX}/bin/fdsh /etc/shells.bak; \
		${ECHO_CMD} ${PREFIX}/bin/fdsh) > /etc/shells; \
		${RM} -f /etc/shells.bak
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${PREFIX}/share/doc/ja/${PORTNAME}
	@for i in ${DOCS_EN}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR}; \
	done
	@for i in ${DOCS_JA}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/ja/${PORTNAME}; \
	done
	@${INSTALL_DATA} ${WRKSRC}/_fdrc.orig ${PREFIX}/etc/fd2rc.dist
	@${INSTALL_DATA} ${WRKSRC}/_fdrc ${PREFIX}/etc/fd2rc.sample
	if [ ! -f ${PREFIX}/etc/fd2rc ]; then \
		${CP} -p ${PREFIX}/etc/fd2rc.sample ${PREFIX}/etc/fd2rc; \
	fi
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
