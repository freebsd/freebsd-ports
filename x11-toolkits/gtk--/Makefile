# New ports collection makefile for:   gtk--
# Version required:    1.0.3
# Date created:        11 May 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	Gtk---1.0.3
PKGNAME=	gtk---1.0.3
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/Gtk--

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_NEWGCC=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static=yes \
		--without-gnome
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"

MAN3=	G_IntList.3 G_IntList_Iterator.3 G_List.3 G_List_Cpp_Iterator.3 \
	G_List_ConstIterator.3 \
	G_List_Iterator.3 G_SList_Iterator.3 GtkBase.3 GtkBaseClass.3 \
	Gtk_AccelEntry.3 Gtk_AccelGroup.3 Gtk_AccelLabel.3 Gtk_Adjustment.3 \
	Gtk_Alignment.3 Gtk_ArgBase.3 Gtk_ArgObject.3 Gtk_ArgSimple.3 \
	Gtk_ArgString.3 Gtk_Arrow.3 Gtk_AspectFrame.3 Gtk_Base.3 \
	Gtk_Base_Class.3 Gtk_Bin.3 Gtk_Box.3 Gtk_Button.3 Gtk_ButtonBox.3 \
	Gtk_CList.3 Gtk_CTree.3 Gtk_CTreeNode.3 Gtk_CTreeRow.3 Gtk_Calendar.3 \
	Gtk_CheckButton.3 Gtk_CheckMenuItem.3 Gtk_ColorSelection.3 \
	Gtk_ColorSelectionDialog.3 Gtk_Combo.3 Gtk_Container.3 Gtk_Curve.3 \
	Gtk_Data.3 Gtk_Dialog.3 Gtk_DrawingArea.3 Gtk_Editable.3 Gtk_Entry.3 \
	Gtk_EventBox.3 Gtk_FileSelection.3 Gtk_Fixed.3 Gtk_FontSelection.3 \
	Gtk_FontSelectionDialog.3 Gtk_Frame.3 Gtk_GammaCurve.3 Gtk_HBox.3 \
	Gtk_HButtonBox.3 Gtk_HPaned.3 Gtk_HRuler.3 Gtk_HScale.3 \
	Gtk_HScrollbar.3 Gtk_HSeparator.3 Gtk_HandleBox.3 Gtk_Image.3 \
	Gtk_InputDialog.3 Gtk_Invisible.3 Gtk_Item.3 Gtk_ItemFactory.3 \
	Gtk_ItemFactory_Menu.3 Gtk_ItemFactory_MenuBar.3 \
	Gtk_ItemFactory_OptionMenu.3 Gtk_Label.3 Gtk_Layout.3 Gtk_List.3 \
	Gtk_ListItem.3 Gtk_Main.3 Gtk_Menu.3 Gtk_MenuBar.3 Gtk_MenuFactory.3 \
	Gtk_MenuItem.3 Gtk_MenuPath.3 Gtk_MenuShell.3 Gtk_Misc.3 \
	Gtk_Notebook.3 Gtk_NotebookPage.3 Gtk_Object.3 Gtk_ObjectHandle.3 \
	Gtk_ObjectHandle_ref.3 Gtk_OptionMenu.3 Gtk_Packer.3 Gtk_Paned.3 \
	Gtk_Pixmap.3 Gtk_Plug.3 Gtk_Preview.3 Gtk_Progress.3 Gtk_ProgressBar.3 \
	Gtk_RC.3 Gtk_RadioButton.3 Gtk_RadioMenuItem.3 Gtk_Range.3 \
	Gtk_RcStyle.3 Gtk_Ruler.3 Gtk_Scale.3 Gtk_Scrollbar.3 \
	Gtk_ScrolledWindow.3 Gtk_Separator.3 Gtk_Socket.3 Gtk_SpinButton.3 \
	Gtk_Statusbar.3 Gtk_Style.3 Gtk_Table.3 Gtk_Text.3 Gtk_TipsQuery.3 \
	Gtk_ToggleButton.3 Gtk_Toolbar.3 Gtk_Tooltips.3 Gtk_Trashcan.3 \
	Gtk_Trashcan_Helper.3 Gtk_Tree.3 Gtk_TreeItem.3 Gtk_VBox.3 \
	Gtk_VButtonBox.3 Gtk_VPaned.3 Gtk_VRuler.3 Gtk_VScale.3 \
	Gtk_VScrollbar.3 Gtk_VSeparator.3 Gtk_Viewport.3 Gtk_Widget.3 \
	Gtk_Window.3 ItemFactoryConnector.3 ItemFactoryConnectorBase.3 \
	MenuFactoryConnector.3 MenuFactoryConnectorBase.3 \
	ToolbarConnector.3 ToolbarConnectorBase.3 Toolbar_Child.3 \
	_gtk_string.3 gtkmm_add_signal_class.3

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
