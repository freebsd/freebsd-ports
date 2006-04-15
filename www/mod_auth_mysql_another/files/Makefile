#
# $FreeBSD$
#
all: build

build:
	%%APXS%% -c -L%%AP_LIB%% -I%%AP_INC%% -lmysqlclient -lm -lz mod_auth_mysql.c

install:
	%%APXS%% -i mod_auth_mysql.so
