# New ports collection makefile for:	ntp
# Date created:		Di   5 Mai 1998 21:31:03 CEST
# Whom:			andreas
#
# $FreeBSD$
#

PORTNAME=	ntp
PORTVERSION=	4.2.0a
CATEGORIES=	net ipv6
YEAR=		2006
MONTH=		01
DAY=		27
SNAPSHOT_DIR=	snapshots/ntp-stable/${YEAR}/${MONTH}
MASTER_SITES=	ftp://ftp.udel.edu/pub/ntp/ntp4/${SNAPSHOT_DIR}/ \
		http://www.eecis.udel.edu/~ntp/ntp_spool/ntp4/${SNAPSHOT_DIR}/ \
		ftp://ftp.archive.de.uu.net/pub/unix/ntp/ntp4/${SNAPSHOT_DIR} \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/ntp/ntp4/${SNAPSHOT_DIR}/
DISTNAME=	${PORTNAME}-stable-${PORTVERSION:S/.r/-rc/}-${YEAR}${MONTH}${DAY}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	The Network Time Protocol Distribution

LATEST_LINK=	${PORTNAME}-stable

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.if defined(ENABLE_RAWDCF)
CONFIGURE_ARGS+=	--enable-RAWDCF
.endif

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--without-crypto
PLIST_SUB+=		SSL="@comment "
.else
USE_OPENSSL=		yes
CONFIGURE_ARGS+=	--with-openssl-incdir=${OPENSSLINC} \
			--with-openssl-libdir=${OPENSSLLIB}
PLIST_SUB+=		SSL=""
.endif

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/conf/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${FIND} ${WRKSRC}/html -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@cd ${WRKSRC}/html && ${FIND} . -print | \
		${CPIO} -pdu -R ${SHAREOWN}:${SHAREGRP} --quiet ${DOCSDIR}
.endif

.include <bsd.port.mk>
