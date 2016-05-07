# Created by: Roman Y. Bogdanov <sam@brj.pp.ru>
# $FreeBSD$

PORTNAME=	mc-light
PORTVERSION=	4.1.40.p9
PORTREVISION=	11
CATEGORIES=	misc shells
MASTER_SITES=	http://mc.linuxinside.com/Releases/
DISTNAME=	mc-${PORTVERSION:S/.p9/-pre9/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight Midnight Commander clone

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	gawk:lang/gawk

CONFLICTS=	mc-4.7*

USES=		gmake iconv pkgconfig shebangfix
SHEBANG_FILES=	vfs/extfs/a vfs/extfs/deb \
		vfs/extfs/iso vfs/extfs/mailfs
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-included-slang \
		--with-gettext \
		--with-vfs \
		--with-netrc \
		--without-gpm-mouse \
		--with-edit

OPTIONS_DEFINE=	NLS SUBSHELL MC_IN_MC
OPTIONS_SUB=	yes

SUBSHELL_DESC=	Build with subshell support (only for bash!)
SUBSHELL_CONFIGURE_WITH=	subshell

MC_IN_MC_DESC=	Allow run mc inside mc (useful for mcedit)
MC_IN_MC_CPPFLAGS=	-DMC_IN_MC_ALLOWED

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

post-patch:
	@${REINPLACE_CMD} '/destdir/ s|gnulocaledir|DESTDIR)$$(&|' \
		${WRKSRC}/po/Makefile.in.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mcserv
.for i in a arfs audio cpio deb esp ftplist hp48 iso lha lslR mailfs patchfs rar rpm trpm uarj uha zip zoo
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/share/mc/extfs/${i}
.endfor

.include <bsd.port.mk>
