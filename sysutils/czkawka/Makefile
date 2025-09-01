PORTNAME=	czkawka
DISTVERSION=	10.0.0
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Simple app to remove unnecessary files from your computer
WWW=		https://github.com/qarmin/czkawka

LICENSE=	CC-BY-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_CC-BY-4.0=	${WRKSRC}/LICENSE_CC_BY_4_ICONS
LICENSE_FILE_MIT=	${WRKSRC}/${PORTNAME}_core/LICENSE_MIT

BROKEN_i386=	the trait bound [u64; 4]: BitViewSized is not satisfied

USES=		cargo desktop-file-utils gnome
USE_GITHUB=	yes
GH_ACCOUNT=	qarmin
USE_GNOME=	gdkpixbuf gtk40

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	${PLIST_FILES:Mbin/*:T}

PLIST_FILES=	bin/${PORTNAME}_cli \
		bin/${PORTNAME}_gui \
		share/applications/com.github.qarmin.czkawka.desktop \
		share/icons/hicolor/scalable/apps/com.github.qarmin.czkawka-symbolic.svg \
		share/icons/hicolor/scalable/apps/com.github.qarmin.czkawka.Devel.svg \
		share/icons/hicolor/scalable/apps/com.github.qarmin.czkawka.svg \
		share/metainfo/com.github.qarmin.czkawka.metainfo.xml

post-patch:
# XXX Skip the new GUI until runtime is tested
	@${REINPLACE_CMD} '/krokiet/d' ${WRKSRC}/Cargo.toml

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/data/icons/*.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/data/*.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
