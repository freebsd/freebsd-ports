# New ports collection makefile for:	iv
# Version required:	3.1
# Date created:		23.sept.1994
# Whom:			adam
#
# $Id: Makefile,v 1.18 1998/12/18 09:40:52 asami Exp $
#

DISTNAME=	3.1
PKGNAME=	iv-3.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://interviews.stanford.edu/pub/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tanimura@naklab.dnj.ynu.ac.jp

USE_XLIB=	yes

DIST_SUBDIR=	iv
WRKSRC=		${WRKDIR}/iv
MAKEFILE=	makefile

MANPREFIX=	${PREFIX}/interviews
MANN=		Adjuster.n Banner.n BasicDialog.n Border.n Box2_6.n \
		BrushCmd.n Button2_6.n CGlue.n CSolver.n Catalog.n \
		Clipboard.n ColorCmd.n Command.n CompletionEditor.n \
		Component.n ComponentView.n ConnectTool.n Connector.n \
		Control.n ControlInfo.n Creator.n Damage.n Data.n \
		Deck2_6.n Dialog.n Dispatcher.n Editor.n EditorInfo.n \
		EllipseComp.n ExternView.n FileBrowser.n FileChooser.n \
		FontCmd.n Frame.n GVUpdater.n Glue2_6.n Graphic.n \
		GraphicBlock.n GraphicComp.n GraphicCompTool.n \
		GraphicView.n Grid.n IOCallback.n IOHandler.n \
		ImportCmd.n Interactor.n Iterator.n KeyMap.n \
		LineComp.n LinkComp.n MacroCmd.n MagnifyTool.n \
		Manipulator.n MatchEditor.n Menu2_6.n Message.n \
		MoveTool.n NOPCmd.n PadComp.n Page.n Painter.n \
		Panner.n Path.n Pattern.n PatternCmd.n Perspective.n \
		Picture.n PinComp.n PolygonComp.n PostScriptView.n \
		RasterComp.n RasterRect.n RectComp.n Regexp.n ReqErr.n \
		ReshapeTool.n Resource.n RotateTool.n RpcHdr.n \
		RpcPeer.n RpcReader.n RpcRegistry.n RpcService.n \
		RpcWriter.n Rubband.n ScaleTool.n Scene.n Scroller.n \
		SelectTool.n Selection.n Sensor.n Shape.n SlotComp.n \
		SplineComp.n StateVar.n StateVarView.n StencilComp.n \
		StrBrowser.n StrChooser.n StretchTool.n StringEditor.n \
		Subject.n TextBuffer.n TextComp.n TextDisplay.n \
		TextEditor.n Tool.n TransferFunct.n Tray.n UArray.n \
		UControl.n UHashTable.n ULabel.n UList.n UMap.n \
		UStencil.n Unidraw.n UnidrawIntro.n Vertices.n \
		VerticesComp.n Viewer.n Viewport.n World.n alert.n \
		align.n catcmds.n classes.n datas.n dclock.n doc.n \
		edit.n ellipses.n geomobjs.n globals.n ibuild.n \
		iclass.n idraw.n ifb.n ifc.n iostreamb.n ivmkmf.n \
		kybd.n lines.n logo.n mailbox.n manips.n polygons.n \
		pspaint.n remind.n rpcbuf.n rpcstream.n splines.n \
		statevars.n stateviews.n struct.n transfns.n \
		transforms.n uctrls.n viewcmds.n

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
IV_LIB_VER=     3
.else
IV_LIB_VER=     3.1
.endif

post-install:
# need these in ${PREFIX}/lib so that ldconfig can find them
	${LN} -fs ../interviews/lib/FREEBSD/libIV.so.${IV_LIB_VER} ${PREFIX}/lib
	${LN} -fs ../interviews/lib/FREEBSD/libUnidraw.so.${IV_LIB_VER} ${PREFIX}/lib
.if ${PORTOBJFORMAT} == "elf"
	${LN} -fs libIV.so.${IV_LIB_VER} ${PREFIX}/lib/libIV.so
	${LN} -fs libUnidraw.so.${IV_LIB_VER} ${PREFIX}/lib/libUnidraw.so
.endif
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
