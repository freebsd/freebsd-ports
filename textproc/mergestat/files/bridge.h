#ifndef _BRIDGE_H
#define _BRIDGE_H

// This file defines a bridge between Golang and sqlite's c extension api.
// Most of sqlite api function defined in <sqlite3ext.h> are macros that redirect calls
// to an instance of sqlite3_api_routines, called as sqlite3_api.

// As neither macros nor c function pointers work directly in cgo, we need to define a bridge
// to redirect calls from golang to sqlite.

// Most of the methods follow the convention of prefixing the sqlite api function with an underscore.
// The bridge isn't extensive and doesn't cover the whole sqlite api.

#include "../sqlite3.h"

//- routine that work with sqlite3_context; see: https://sqlite.org/c3ref/context.html
//-----------------------------

void* _sqlite3_aggregate_context(sqlite3_context *, int);
sqlite3* _sqlite3_context_db_handle(sqlite3_context*);
void* _sqlite3_user_data(sqlite3_context *);
void* _sqlite3_get_auxdata(sqlite3_context *, int);
void  _sqlite3_set_auxdata(sqlite3_context *, int, void *, void (*)(void *));

void _sqlite3_result_blob0(sqlite3_context *, const void *, int, void (*)(void *));
void _sqlite3_result_blob64(sqlite3_context *, const void *, sqlite3_uint64, void (*)(void *));
void _sqlite3_result_double(sqlite3_context *, double);
void _sqlite3_result_error(sqlite3_context *, const char *, int);
void _sqlite3_result_error_code(sqlite3_context *, int);
void _sqlite3_result_error_nomem(sqlite3_context *);
void _sqlite3_result_error_toobig(sqlite3_context *);
void _sqlite3_result_int(sqlite3_context *, int);
void _sqlite3_result_int64(sqlite3_context *, sqlite_int64);
void _sqlite3_result_null(sqlite3_context *);
void _sqlite3_result_text0(sqlite3_context *, const char *, int, void (*)(void *));
void _sqlite3_result_value(sqlite3_context *, sqlite3_value *);
void _sqlite3_result_pointer(sqlite3_context *, void *, const char *, void (*)(void *));
void _sqlite3_result_zeroblob(sqlite3_context *, int);
int _sqlite3_result_zeroblob64(sqlite3_context *, sqlite3_uint64);
void _sqlite3_result_subtype(sqlite3_context *ctx, unsigned int v);

// routines that work with sqlite_stmt; see: https://sqlite.org/c3ref/stmt.html
//-----------------------------

// constructor + destructor
int _sqlite3_prepare_v2(sqlite3 *, const char *, int, sqlite3_stmt **, const char **);
int _sqlite3_finalize(sqlite3_stmt*);

// stepping / executing a prepared statement
int _sqlite3_step(sqlite3_stmt *);
int _sqlite3_reset(sqlite3_stmt *);
int _sqlite3_clear_bindings(sqlite3_stmt *);
int _sqlite3_data_count(sqlite3_stmt *);
int _sqlite3_column_count(sqlite3_stmt *);
sqlite3* _sqlite3_db_handle(sqlite3_stmt*);

// binding values to prepared statement
int _sqlite3_bind_blob(sqlite3_stmt *, int, const void *, int, void (*)(void *));
int _sqlite3_bind_double(sqlite3_stmt *, int, double);
int _sqlite3_bind_int(sqlite3_stmt *, int, int);
int _sqlite3_bind_int64(sqlite3_stmt *, int, sqlite_int64);
int _sqlite3_bind_null(sqlite3_stmt *, int);
int _sqlite3_bind_text(sqlite3_stmt *, int, const char *, int, void (*)(void *));
int _sqlite3_bind_value(sqlite3_stmt *, int, const sqlite3_value *);
int _sqlite3_bind_zeroblob(sqlite3_stmt *, int, int);
int _sqlite3_bind_zeroblob64(sqlite3_stmt *, int, sqlite3_uint64);
int _sqlite3_bind_pointer(sqlite3_stmt *, int, void *, const char *, void (*)(void *));

int _sqlite3_bind_parameter_count(sqlite3_stmt *);
int _sqlite3_bind_parameter_index(sqlite3_stmt *, const char *);
const char* _sqlite3_bind_parameter_name(sqlite3_stmt *, int);

// reading result values from an sqlite3_stmt
const void* _sqlite3_column_blob(sqlite3_stmt*, int);
double _sqlite3_column_double(sqlite3_stmt*, int);
int _sqlite3_column_int(sqlite3_stmt*, int);
sqlite3_int64 _sqlite3_column_int64(sqlite3_stmt*, int);
const unsigned char* _sqlite3_column_text(sqlite3_stmt*, int);
const void* _sqlite3_column_text16(sqlite3_stmt*, int);
sqlite3_value* _sqlite3_column_value(sqlite3_stmt*, int);
int _sqlite3_column_bytes(sqlite3_stmt*, int);
int _sqlite3_column_bytes16(sqlite3_stmt*, int);

// query sqlite3_stmt column information
const char* _sqlite3_column_name(sqlite3_stmt*, int);
int _sqlite3_column_type(sqlite3_stmt*, int);
const char *_sqlite3_column_database_name(sqlite3_stmt *, int);
const char *_sqlite3_column_table_name(sqlite3_stmt *, int);
const char *_sqlite3_column_origin_name(sqlite3_stmt *, int);

// meta-information about the statement itself
int _sqlite3_stmt_readonly(sqlite3_stmt*);

// routines to extract value from sqlite3_value type; see: https://sqlite.org/c3ref/value.html
//-----------------------------

const void *_sqlite3_value_blob(sqlite3_value *);
double _sqlite3_value_double(sqlite3_value *);
int _sqlite3_value_int(sqlite3_value *);
sqlite_int64 _sqlite3_value_int64(sqlite3_value *);
const unsigned char* _sqlite3_value_text(sqlite3_value *);
int _sqlite3_value_bytes(sqlite3_value *);
int _sqlite3_value_type(sqlite3_value *);
unsigned int _sqlite3_value_subtype(sqlite3_value *val);
int _sqlite3_value_numeric_type(sqlite3_value *);
void* _sqlite3_value_pointer(sqlite3_value *, const char *);
int _sqlite3_value_nochange(sqlite3_value*);

// routines to register application-defined sql functions
//-----------------------------

int _sqlite3_create_collation_v2(sqlite3 *, const char *, int, void *, int (*)(void *, int, const void *, int, const void *), void (*)(void *));
int _sqlite3_create_function_v2(sqlite3 *, const char *, int, int, void *, void (*)(sqlite3_context *, int, sqlite3_value **), void (*)(sqlite3_context *, int, sqlite3_value **), void (*)(sqlite3_context *), void (*)(void *));
int _sqlite3_create_window_function(sqlite3 *, const char *, int, int, void *, void (*)(sqlite3_context *, int, sqlite3_value **), void (*)(sqlite3_context *), void (*)(sqlite3_context *), void (*)(sqlite3_context *, int, sqlite3_value **), void (*)(void *));

// memory related operations
void  _sqlite3_free(void *);
void* _sqlite3_malloc(int);
void* _sqlite3_realloc(void *, int);

// error details handler
int _sqlite3_errcode(sqlite3 *);
const char *_sqlite3_errmsg(sqlite3 *);

// auth+tracing
int _sqlite3_set_authorizer(sqlite3 *, int (*)(void *, int, const char *, const char *, const char *, const char *), void *);
int _sqlite3_trace_v2(sqlite3 *, unsigned int, int (*)(unsigned int, void *, void *, void *), void *);

// hooks
void* _sqlite3_commit_hook(sqlite3 *, int (*)(void *), void *);
void* _sqlite3_rollback_hook(sqlite3 *, void (*)(void *), void *);
void* _sqlite3_update_hook(sqlite3 *, void (*)(void *, int, const char *, const char *, sqlite_int64), void *);

// version number information
sqlite_int64 _sqlite3_last_insert_rowid(sqlite3 *);
const char* _sqlite3_libversion(void);
int _sqlite3_libversion_number(void);

// Virtual table routines
int _sqlite3_create_module_v2(sqlite3 *, const char *, const sqlite3_module *, void *, void (*)(void *));
int _sqlite3_declare_vtab(sqlite3 *, const char *);

// miscellaneous routines
int _sqlite3_get_autocommit(sqlite3 *);
int _sqlite3_enable_shared_cache(int);
void _sqlite3_interrupt(sqlite3 *);
int _sqlite3_release_memory(int);
int _sqlite3_threadsafe(void);
int _sqlite3_limit(sqlite3*, int, int);

#endif // _BRIDGE_H

