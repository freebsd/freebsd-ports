# New ports collection makefile for:	iv
# Date created:		23.sept.1994
# Whom:			adam
#
# $FreeBSD$
#

PORTNAME=	iv
PORTVERSION=	3.2a
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.sgi.com/graphics/interviews/
DISTNAME=	${PORTVERSION}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tanimura@FreeBSD.org

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4

USE_XLIB=	yes
INSTALLS_SHLIB=	yes

DIST_SUBDIR=	iv
WRKSRC=		${WRKDIR}/iv
MAKEFILE=	makefile

MANPREFIX=	${PREFIX}/interviews
MANN=		Adjuster.n Banner.n BasicDialog.n Border.n \
		Box2_6.n BrushCmd.n Button2_6.n CGlue.n \
		CSolver.n Catalog.n Clipboard.n ColorCmd.n \
		Command.n CompletionEditor.n Component.n ComponentView.n \
		ConnectTool.n Connector.n Control.n ControlInfo.n \
		Creator.n Damage.n Data.n Deck2_6.n \
		Dialog.n Dispatcher.n Editor.n EditorInfo.n \
		EllipseComp.n ExternView.n FileBrowser.n FileChooser.n \
		FontCmd.n Frame.n GVUpdater.n Glue2_6.n \
		Graphic.n GraphicBlock.n GraphicComp.n GraphicCompTool.n \
		GraphicView.n Grid.n IOCallback.n IOHandler.n \
		ImportCmd.n Interactor.n Iterator.n KeyMap.n \
		LineComp.n LinkComp.n MacroCmd.n MagnifyTool.n \
		Manipulator.n MatchEditor.n Menu2_6.n Message.n \
		MoveTool.n NOPCmd.n PadComp.n Page.n \
		Painter.n Panner.n Path.n Pattern.n \
		PatternCmd.n Perspective.n Picture.n PinComp.n \
		PolygonComp.n PostScriptView.n RasterComp.n RasterRect.n \
		RectComp.n Regexp.n ReqErr.n ReshapeTool.n \
		Resource.n RotateTool.n RpcHdr.n RpcPeer.n \
		RpcReader.n RpcRegistry.n RpcService.n RpcWriter.n \
		Rubband.n ScaleTool.n Scene.n Scroller.n \
		SelectTool.n Selection.n Sensor.n Shape.n \
		SlotComp.n SplineComp.n StateVar.n StateVarView.n \
		StencilComp.n StrBrowser.n StrChooser.n StretchTool.n \
		StringEditor.n Subject.n TextBuffer.n TextComp.n \
		TextDisplay.n TextEditor.n Tool.n TransferFunct.n \
		Tray.n UArray.n UControl.n UHashTable.n \
		ULabel.n UList.n UMap.n UStencil.n \
		Unidraw.n UnidrawIntro.n Vertices.n VerticesComp.n \
		Viewer.n Viewport.n World.n alert.n \
		align.n catcmds.n classes.n datas.n \
		dclock.n doc.n edit.n ellipses.n \
		geomobjs.n globals.n ibuild.n iclass.n \
		idraw.n ifb.n ifc.n iostreamb.n \
		ivmkmf.n kybd.n lines.n logo.n \
		mailbox.n manips.n polygons.n pspaint.n \
		remind.n rpcbuf.n rpcstream.n splines.n \
		statevars.n stateviews.n struct.n transfns.n \
		transforms.n uctrls.n viewcmds.n

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
IV_LIB_VER=	3
.else
IV_LIB_VER=	3.2
.endif

.if ${OSVERSION} >= 400002
post-patch:
	@(cd ${WRKSRC}/src/config/InterViews; ${MV} -f iv-freebsd.cf \
	iv-freebsd.cf~; ${SED} -e 's/\-lg\+\+//' iv-freebsd.cf~ > iv-freebsd.cf)
.endif

post-install:
# need these in ${PREFIX}/lib so that ldconfig can find them
	${LN} -fs ../interviews/lib/FREEBSD/libIV.so.${IV_LIB_VER} ${PREFIX}/lib
	${LN} -fs ../interviews/lib/FREEBSD/libUnidraw.so.${IV_LIB_VER} ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "elf"
	${LN} -fs libIV.so.${IV_LIB_VER} ${PREFIX}/lib/libIV.so
	${LN} -fs libUnidraw.so.${IV_LIB_VER} ${PREFIX}/lib/libUnidraw.so
	${LN} -fs libIV.so.${IV_LIB_VER} ${PREFIX}/interviews/lib/FREEBSD/libIV.so
	${LN} -fs libUnidraw.so.${IV_LIB_VER} ${PREFIX}/interviews/lib/FREEBSD/libUnidraw.so
.endif

.include <bsd.port.post.mk>
