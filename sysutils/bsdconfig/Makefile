# Created by: Devin Teske <dteske@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdconfig
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://druidbsd.sourceforge.net/download/bsdconfig/
DISTNAME=	${PORTNAME}.130705

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-${PORTVERSION}.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to configure various aspects of FreeBSD

LICENSE=	BSD2CLAUSE

USES=		tar:txz
NO_WRKSUBDIR=	yes
PORTEXAMPLES=	browse_packages.sh bsdconfigrc

BSDCFG_LIBE=	libexec/bsdconfig
BSDCFG_SHARE=	share/bsdconfig

MAKE_ARGS+=	LIBEXECDIR="${PREFIX}/libexec" \
		MANDIR="${PREFIX}/man/man" \
		SBINDIR="${PREFIX}/sbin" \
		SHAREDIR="${PREFIX}/share"

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
.  if ${OSVERSION} < 900030
IGNORE=	requires FreeBSD 9.0 or later
.  endif
.else
IGNORE= is a FreeBSD-specific port
.endif

post-patch:
	@${GREP} -Ilrs '^BSDCFG_LIBE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_LIBE="\)[^"]*\(.*\)|\1${PREFIX}/libexec/${PORTNAME}\2|'
	@${GREP} -Ilrs '^BSDCFG_LIBE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_LOCAL_LIBE="\)[^"]*\(.*\)|\1${PREFIX}/libexec/${PORTNAME}\2|'
	@${GREP} -Ilrs '^BSDCFG_SHARE=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^\(BSDCFG_SHARE=\).*|\1"${PREFIX}/share/${PORTNAME}"|'
	@${REINPLACE_CMD} \
		-e 's|^\(BSDCONFIG=\).*|\1${PREFIX}/sbin/${PORTNAME}|' \
		${WRKSRC}/dot/dot

.include <bsd.port.post.mk>
