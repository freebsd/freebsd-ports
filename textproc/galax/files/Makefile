#########################################################################
#                                                                       #
#                                  GALAX                                #
#                             XML Query Engine                          #
#                                                                       #
#   Copyright 2000, Lucent Technologies.                                #
#   Distributed only by permission.                                     #
#                                                                       #
#########################################################################

# $Id: Makefile.unix,v 1.8 2002/10/12 00:33:30 simeon Exp $ #
# $FreeBSD$ #

# This config should work under Unix

########################################################################
# Location of O'Caml compilers and libraries

OCAMLHOME=$(PREFIX)/lib/ocaml
OCAMLBIN=$(PREFIX)/bin

########################################################################
# Where do you want to install Galax after it has been compiled?

GALAXHOME=$(PREFIX)/Galax-0.2.0

BINDIR=$(GALAXHOME)/bin
LIBDIR=$(GALAXHOME)/lib
MANDIR=$(GALAXHOME)

###########################################################################
# Character encoding configuration

ENCODINGS=utf8 #iso88591 utf8
# The list of currently available encodings is: iso88591 and utf8

# Note that support for each encoding does add to the size of the
# resulting Galax executables.

###########################################################################
# APIs configuration

#
# Notes:
#	- the Java API is not available in native mode
#	- the Java API requires the C API
#

APIS=c #java
OPTAPIS=c

# C & C++ compilers (only required if you want to use the C and C++ APIs)

CC?=gcc
CPP?=g++
LD=ld

# Compiling the C & C++ APIs often requires additional libaries,
# depending on your compiler.
#
# A good hint is to look for the BYTECCLIBS variable inside
# ./config/Makefile in the Objective Caml source after it has been
# configured.

# Works with Linux i386 + gcc
WITH_CLIBS=-lm -lcurses

# Works with Solaris 2.6 + cc
#WITH_CLIBS=-lcurses -lnsl -lsocket -lm -ldl -lunix -lstr

# Which parameters to ld to create a shared library?

SHARED=-shared --whole-archive
#SHARED=-G -z allextract

# Java compilers (only required if you want to use the Java API)

JAVAC=javac
#JAVAH=javah

# For the Java library, the Java home directory and include directory
# where jni.h is located

JAVAHOME=$(JAVA_HOME)

# Works for IBM jdk
JAVAINCLUDE=$(JAVAHOME)/include

# Reported to work for SUN jdk
#JAVAINCLUDE=$(JAVAHOME)/include/linux


##########################################################################
# The following is only needed if you are running the regression tests
#
# Location of Perl

PERL=perl

###########################################################################
# YOU SHOULD NOT NEED TO MODIFY BELOW THIS LINE

###########################################################################
# Architecture

ARCH=FreeBSD

###########################################################################
# Executable extension's configuration

EXE=             # Extension for executables
OPT=.opt         # Extension for native code executables
BYTE=.byte       # Extension for bytecode code executables
CGI=.cgi         # Extension for byte code CGI scripts
OPTCGI=opt.cgi   # Extension for native code CGI scripts
ZIPEXT=.tar.gz   # Extension for packages

###########################################################################
# Command-line tools

CP=cp
MKDIR=mkdir -p
RANLIB=ranlib
AR=ar
LN=ln -s -f
RM=rm -f
TOUCH=touch
ZIP=tar cvf
ZIPOPT=--gzip
