# New ports collection makefile for:	p5-Syntax-Highlight-Engine-Kate
# Date created:				29 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Syntax-Highlight-Engine-Kate
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A port of the syntax highlight engine of the Kate texteditor

MAN3=	Syntax::Highlight::Engine::Kate.3 \
	Syntax::Highlight::Engine::Kate::ABC.3 \
	Syntax::Highlight::Engine::Kate::AHDL.3 \
	Syntax::Highlight::Engine::Kate::ANSI_C89.3 \
	Syntax::Highlight::Engine::Kate::ASP.3 \
	Syntax::Highlight::Engine::Kate::AVR_Assembler.3 \
	Syntax::Highlight::Engine::Kate::AWK.3 \
	Syntax::Highlight::Engine::Kate::Ada.3 \
	Syntax::Highlight::Engine::Kate::Alerts.3 \
	Syntax::Highlight::Engine::Kate::Ansys.3 \
	Syntax::Highlight::Engine::Kate::Apache_Configuration.3 \
	Syntax::Highlight::Engine::Kate::Asm6502.3 \
	Syntax::Highlight::Engine::Kate::Bash.3 \
	Syntax::Highlight::Engine::Kate::BibTeX.3 \
	Syntax::Highlight::Engine::Kate::C.3 \
	Syntax::Highlight::Engine::Kate::CGiS.3 \
	Syntax::Highlight::Engine::Kate::CMake.3 \
	Syntax::Highlight::Engine::Kate::CSS.3 \
	Syntax::Highlight::Engine::Kate::CSS_PHP.3 \
	Syntax::Highlight::Engine::Kate::CUE_Sheet.3 \
	Syntax::Highlight::Engine::Kate::Cdash.3 \
	Syntax::Highlight::Engine::Kate::Cg.3 \
	Syntax::Highlight::Engine::Kate::ChangeLog.3 \
	Syntax::Highlight::Engine::Kate::Cisco.3 \
	Syntax::Highlight::Engine::Kate::Clipper.3 \
	Syntax::Highlight::Engine::Kate::ColdFusion.3 \
	Syntax::Highlight::Engine::Kate::Common_Lisp.3 \
	Syntax::Highlight::Engine::Kate::ComponentminusPascal.3 \
	Syntax::Highlight::Engine::Kate::Cplusplus.3 \
	Syntax::Highlight::Engine::Kate::D.3 \
	Syntax::Highlight::Engine::Kate::De_DE.3 \
	Syntax::Highlight::Engine::Kate::Debian_Changelog.3 \
	Syntax::Highlight::Engine::Kate::Debian_Control.3 \
	Syntax::Highlight::Engine::Kate::Desktop.3 \
	Syntax::Highlight::Engine::Kate::Diff.3 \
	Syntax::Highlight::Engine::Kate::Doxygen.3 \
	Syntax::Highlight::Engine::Kate::E_Language.3 \
	Syntax::Highlight::Engine::Kate::Eiffel.3 \
	Syntax::Highlight::Engine::Kate::Email.3 \
	Syntax::Highlight::Engine::Kate::En_US.3 \
	Syntax::Highlight::Engine::Kate::Euphoria.3 \
	Syntax::Highlight::Engine::Kate::Ferite.3 \
	Syntax::Highlight::Engine::Kate::Fortran.3 \
	Syntax::Highlight::Engine::Kate::FourGL.3 \
	Syntax::Highlight::Engine::Kate::FourGLminusPER.3 \
	Syntax::Highlight::Engine::Kate::FreeBASIC.3 \
	Syntax::Highlight::Engine::Kate::GDL.3 \
	Syntax::Highlight::Engine::Kate::GLSL.3 \
	Syntax::Highlight::Engine::Kate::GNU_Assembler.3 \
	Syntax::Highlight::Engine::Kate::GNU_Gettext.3 \
	Syntax::Highlight::Engine::Kate::HTML.3 \
	Syntax::Highlight::Engine::Kate::Haskell.3 \
	Syntax::Highlight::Engine::Kate::IDL.3 \
	Syntax::Highlight::Engine::Kate::ILERPG.3 \
	Syntax::Highlight::Engine::Kate::INI_Files.3 \
	Syntax::Highlight::Engine::Kate::Inform.3 \
	Syntax::Highlight::Engine::Kate::Intel_x86_NASM.3 \
	Syntax::Highlight::Engine::Kate::JSP.3 \
	Syntax::Highlight::Engine::Kate::Java.3 \
	Syntax::Highlight::Engine::Kate::JavaScript.3 \
	Syntax::Highlight::Engine::Kate::JavaScript_PHP.3 \
	Syntax::Highlight::Engine::Kate::Javadoc.3 \
	Syntax::Highlight::Engine::Kate::KBasic.3 \
	Syntax::Highlight::Engine::Kate::Kate_File_Template.3 \
	Syntax::Highlight::Engine::Kate::LDIF.3 \
	Syntax::Highlight::Engine::Kate::LPC.3 \
	Syntax::Highlight::Engine::Kate::LaTeX.3 \
	Syntax::Highlight::Engine::Kate::Lex_Flex.3 \
	Syntax::Highlight::Engine::Kate::LilyPond.3 \
	Syntax::Highlight::Engine::Kate::Literate_Haskell.3 \
	Syntax::Highlight::Engine::Kate::Logtalk.3 \
	Syntax::Highlight::Engine::Kate::Lua.3 \
	Syntax::Highlight::Engine::Kate::M3U.3 \
	Syntax::Highlight::Engine::Kate::MABminusDB.3 \
	Syntax::Highlight::Engine::Kate::MIPS_Assembler.3 \
	Syntax::Highlight::Engine::Kate::Makefile.3 \
	Syntax::Highlight::Engine::Kate::Mason.3 \
	Syntax::Highlight::Engine::Kate::Matlab.3 \
	Syntax::Highlight::Engine::Kate::Modulaminus2.3 \
	Syntax::Highlight::Engine::Kate::Music_Publisher.3 \
	Syntax::Highlight::Engine::Kate::Nl.3 \
	Syntax::Highlight::Engine::Kate::Objective_Caml.3 \
	Syntax::Highlight::Engine::Kate::ObjectiveminusC.3 \
	Syntax::Highlight::Engine::Kate::Octave.3 \
	Syntax::Highlight::Engine::Kate::PHP_HTML.3 \
	Syntax::Highlight::Engine::Kate::PHP_PHP.3 \
	Syntax::Highlight::Engine::Kate::POVminusRay.3 \
	Syntax::Highlight::Engine::Kate::Pascal.3 \
	Syntax::Highlight::Engine::Kate::Perl.3 \
	Syntax::Highlight::Engine::Kate::PicAsm.3 \
	Syntax::Highlight::Engine::Kate::Pike.3 \
	Syntax::Highlight::Engine::Kate::PostScript.3 \
	Syntax::Highlight::Engine::Kate::Progress.3 \
	Syntax::Highlight::Engine::Kate::Prolog.3 \
	Syntax::Highlight::Engine::Kate::PureBasic.3 \
	Syntax::Highlight::Engine::Kate::Python.3 \
	Syntax::Highlight::Engine::Kate::Quake_Script.3 \
	Syntax::Highlight::Engine::Kate::REXX.3 \
	Syntax::Highlight::Engine::Kate::RPM_Spec.3 \
	Syntax::Highlight::Engine::Kate::RSI_IDL.3 \
	Syntax::Highlight::Engine::Kate::R_Script.3 \
	Syntax::Highlight::Engine::Kate::RenderMan_RIB.3 \
	Syntax::Highlight::Engine::Kate::Ruby.3 \
	Syntax::Highlight::Engine::Kate::SGML.3 \
	Syntax::Highlight::Engine::Kate::SML.3 \
	Syntax::Highlight::Engine::Kate::SQL.3 \
	Syntax::Highlight::Engine::Kate::SQL_MySQL.3 \
	Syntax::Highlight::Engine::Kate::SQL_PostgreSQL.3 \
	Syntax::Highlight::Engine::Kate::Sather.3 \
	Syntax::Highlight::Engine::Kate::Scheme.3 \
	Syntax::Highlight::Engine::Kate::Scilab.3 \
	Syntax::Highlight::Engine::Kate::Sieve.3 \
	Syntax::Highlight::Engine::Kate::Spice.3 \
	Syntax::Highlight::Engine::Kate::Stata.3 \
	Syntax::Highlight::Engine::Kate::TI_Basic.3 \
	Syntax::Highlight::Engine::Kate::TaskJuggler.3 \
	Syntax::Highlight::Engine::Kate::Tcl_Tk.3 \
	Syntax::Highlight::Engine::Kate::Template.3 \
	Syntax::Highlight::Engine::Kate::Txt2tags.3 \
	Syntax::Highlight::Engine::Kate::UnrealScript.3 \
	Syntax::Highlight::Engine::Kate::VHDL.3 \
	Syntax::Highlight::Engine::Kate::VRML.3 \
	Syntax::Highlight::Engine::Kate::Velocity.3 \
	Syntax::Highlight::Engine::Kate::Verilog.3 \
	Syntax::Highlight::Engine::Kate::WINE_Config.3 \
	Syntax::Highlight::Engine::Kate::Wikimedia.3 \
	Syntax::Highlight::Engine::Kate::XHarbour.3 \
	Syntax::Highlight::Engine::Kate::XML.3 \
	Syntax::Highlight::Engine::Kate::XML_Debug.3 \
	Syntax::Highlight::Engine::Kate::Xorg_Configuration.3 \
	Syntax::Highlight::Engine::Kate::Xslt.3 \
	Syntax::Highlight::Engine::Kate::Yacas.3 \
	Syntax::Highlight::Engine::Kate::Yacc_Bison.3

PERL_CONFIGURE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/bin/*.pl ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
